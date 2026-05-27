//
//  ViewController.swift
//  DemoSwiftApp
//
//  Created by DATA MOTION PTE. LTD. on 09.06.21.
//  Copyright © 2021 DATA MOTION PTE. LTD. All rights reserved.
//

import UIKit
import TelematicsSDK

class ViewController: UIViewController {
    
    @IBOutlet weak var stateLabel : UILabel!
    @IBOutlet weak var permissionLabel : UILabel!
    @IBOutlet weak var currentSpeedLabel : UILabel!
    @IBOutlet weak var tripsView : UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //DEVICE ID REQUIRED!
        let deviceId = "YOUR_DEVICE_ID" //REQUIRED!
        do {
            try RPEntry.instance.setDeviceID(deviceId: deviceId)
        } catch {
            print(error.localizedDescription)
        }
        
        RPEntry.instance.locationDelegate = self
        RPEntry.instance.trackingStateDelegate = self
        RPEntry.instance.speedLimitDelegate = self
        RPEntry.instance.accuracyAuthorizationDelegate = self
        RPEntry.instance.lowPowerModeDelegate = self
    }
    
    override func viewDidAppear(_ animated: Bool) {
        self.observePermissions()
    }
    
    deinit {
        RPEntry.instance.locationDelegate = nil
        RPEntry.instance.trackingStateDelegate = nil
        RPEntry.instance.speedLimitDelegate = nil
        RPEntry.instance.accuracyAuthorizationDelegate = nil
        RPEntry.instance.lowPowerModeDelegate = nil
    }
    
    func showNotification(title: String, body: String) {
        let content = UNMutableNotificationContent()
        content.title = title
        content.subtitle = body
        content.sound = UNNotificationSound.default

        // show this notification five seconds from now
        let trigger = UNTimeIntervalNotificationTrigger(
            timeInterval: 5,
            repeats: false
        )

        // choose a random identifier
        let request = UNNotificationRequest(
            identifier: UUID().uuidString,
            content: content,
            trigger: trigger
        )

        // add our notification request
        UNUserNotificationCenter.current().add(request)
    }
    
    @objc func observePermissions() {
        DispatchQueue.main.async {
            let isActive = RPEntry.instance.isTracking()
            self.stateLabel.text = "Tracking = \(isActive)"
            let permissions = RPEntry.instance.isAllRequiredPermissionsAndSensorsGranted()
            self.permissionLabel.text = "All Permission Granted = \(permissions)"
            
        }
        RPEntry.instance.api.getTracksWithOffset(0, limit: 10) { [weak self] tracks, error in
            DispatchQueue.main.async { [weak self] in
                self?.tripsView.text = ""
                
                if let error {
                    self?.tripsView.text = "trips load error = \(error.localizedDescription)"
                    return
                }
                
                for track in tracks {
                    let currentText = self?.tripsView.text ?? ""
                    self?.tripsView.text = "\(currentText)\n\(track.trackToken)\n\(track.startDate)\n\(track.endDate)\n"
                }
            }
        }
    }
    
    @objc func changedActivity() {
        DispatchQueue.main.async {
            
        }
    }

}

extension ViewController: RPLocationDelegate {
    
    func onLocationChanged(_ location: CLLocation) {
        DispatchQueue.main.async { [weak self] in
            self?.currentSpeedLabel.text = String(format: "speed = %.2f km/h", location.speed)
        }
        print("location = %@", location)
    }
    
    func onNewEvents(_ events: [RPEventPoint]) {
        for event in events {
            print("event = %@", event)
        }
    }
}

extension ViewController: RPSpeedLimitDelegate {
    
    var timeThreshold: TimeInterval { 5 }
    var speedLimit: Double { 100 }
    
    func speedLimitNotification(
        _ speedLimit: Double,
        speed: Double,
        latitude: Double,
        longitude: Double,
        date: Date
    ) {
        self.showNotification(
            title: "Overspeed",
            body: String(format: "You speed is %f at lat: %f lon:%f", speed, latitude, longitude)
        )
    }
    
}

extension ViewController: RPTrackingStateListenerDelegate {
    
    func trackingStateChanged(_ state: Bool) {
        self.stateLabel.text = "Tracking = \(state)"
        var body = "Tracking Stopped"
        if state {
            body = "Tracking Started"
        }
        self.showNotification(
            title: "Tracking State",
            body: body
        )
    }
    
}

extension ViewController: RPAccuracyAuthorizationDelegate {
    
    func wrongAccuracyAuthorization() {
        self.showNotification(
            title: "Precise Location is off",
            body: "Your trips may be not recorded. Please, follow to App Settings=>Location=>Precise Location"
        )
    }
    
}

extension ViewController: RPLowPowerModeDelegate {
    
    func lowPowerMode(_ state: Bool) {
        if (state) {
            self.showNotification(
                title: "Low Power Mode",
                body: "Your trips may be not recorded. Please, follow to Settings=>Battery=>Low Power"
            )
        }
    }
    
}

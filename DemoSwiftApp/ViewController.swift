//
//  ViewController.swift
//  DemoSwiftApp
//
//  Created by DATA MOTION PTE. LTD. on 09.06.21.
//  Copyright © 2021 DATA MOTION PTE. LTD. All rights reserved.
//

import UIKit
import RaxelPulse

class ViewController: UIViewController {
    
    @IBOutlet weak var stateLabel : UILabel!
    @IBOutlet weak var permissionLabel : UILabel!
    @IBOutlet weak var currentSpeedLabel : UILabel!
    @IBOutlet weak var tripsView : UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        NotificationCenter.default.addObserver(self, selector: #selector(self.changedActivity), name: .RPTrackerDidChangeActivity, object: nil)
        RPEntry.instance().currentSpeed { [weak self](speedvalue) in
            guard let strongSelf = self else {
                return
            }
            var result = "speed = 0 km/h"
            if speedvalue.floatValue > 0 {
                result = String(format: "speed = %.2f km/h", speedvalue.floatValue)
            }
            strongSelf.currentSpeedLabel.text = result
        }
    }
    
    override func viewDidAppear(_ animated: Bool) {
        self.observePermissions()
    }
    
    @objc func observePermissions() {
        DispatchQueue.main.async {
            let isActive = RPTracker.instance().isActive
            self.stateLabel.text = "Tracking = \(isActive)"
            let permissions = RPPermissionsWizard.isAllRequiredPermissionsGranted()
            self.permissionLabel.text = "All Permission Granted = \(permissions)"
            
        }
        RPEntry.instance().api.getTracks(0, limit: 1000) { (feed, error) in
            DispatchQueue.main.async {
                self.tripsView.text = ""
            }
            if error != nil {
                DispatchQueue.main.async {
                    self.tripsView.text = "trips load error = \(error?.localizedDescription ?? "empty")"
                }
            }
            if let theFeed = feed as? RPFeed {
                for track in theFeed.tracks {
                    DispatchQueue.main.async {
                        self.tripsView.text = "\(self.tripsView.text ?? "")\n\(track.trackToken ?? "")\n\(track.startDate ?? NSDate.now)\n\(track.endDate ?? NSDate.now)\n"
                    }
                }
            }
        }
    }
    
    @objc func changedActivity() {
        DispatchQueue.main.async {
            let isActive = RPTracker.instance().isActive
            self.stateLabel.text = "Tracking = \(isActive)"
        }
    }

}


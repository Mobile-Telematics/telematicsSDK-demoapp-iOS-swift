//
//  AppDelegate.swift
//  DemoSwiftApp
//
//  Created by DATA MOTION PTE. LTD. on 09.06.21.
//  Copyright © 2021 DATA MOTION PTE. LTD. All rights reserved.
//

import UIKit
import RaxelPulse
import AdSupport

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, RPSpeedLimitDelegate, RPTrackingStateListenerDelegate, RPAccuracyAuthorizationDelegate, RPLowPowerModeDelegate, RPLocationDelegate {
    func onNewEvents(_ events: NSMutableArray!) {
        //
    }
    
    
    var timeThreshold: TimeInterval = 5

    var speedLimit: Double = 100

    func speedLimitNotification(_ speedLimit: Double, speed: Double, latitude: Double, longitude: Double, date: Date!) {
        self.showNotification(title: "Overspeed", body: String(format: "You speed is %f at lat: %f lon:%f", speed, latitude, longitude))
    }

    func trackingStateChanged(_ state: Bool) {
        var body = "Tracking Stoped"
        if state {
            body = "Tracking Started"
        }
        self.showNotification(title: "Tracking State", body: body)
    }

    func wrongAccuracyAuthorization() {
        self.showNotification(title: "Precise Location is off", body: "Your trips may be not recorded. Please, follow to App Settings=>Location=>Precise Location")
    }

    func lowPowerMode(_ state: Bool) {
        if (state) {
            self.showNotification(title: "Low Power Mode", body: "Your trips may be not recorded. Please, follow to Settings=>Battery=>Low Power")
        }
    }

    func onLocationChanged(_ location: CLLocation!) {
        NSLog("location = %@", location)
    }
    
    func showNotification(title: String, body: String) {
        let content = UNMutableNotificationContent()
        content.title = title
        content.subtitle = body
        content.sound = UNNotificationSound.default

        // show this notification five seconds from now
        let trigger = UNTimeIntervalNotificationTrigger(timeInterval: 5, repeats: false)

        // choose a random identifier
        let request = UNNotificationRequest(identifier: UUID().uuidString, content: content, trigger: trigger)

        // add our notification request
        UNUserNotificationCenter.current().add(request)
    }

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        let appName = "\"Swift Demo App\""
        let pages = [
            PageHelper.createPage(
                pageHeader   : "Attention Required!",
                pageText     : "\n\nYou will receive a popup shortly. This popup will ask you for access to your location even when you are not using the app.\n\nPlease, choose ",
                pageBoldText : "“Allow while using App”",
                lastPageText : " for \(appName) to automatically detect when you start a trip.",
                alertHeader  : "Allow \(appName) to access your location?",
                alertText    : "\n\nWe use location service for evaluating your driving manner. By enabling “Always While Using App” on location, the app will be able to automatically determine when you have started and ended a drive",
                buttonTexts  : ["Allow while using App", "Allow Once", "Don’t Allow"],
                coloredButton: "Allow while using App"),
            PageHelper.createPage(
                pageHeader   : "Attention Required!",
                pageText     : "\n\nThen, You will receive a popup to grant us access to your Motion & Fitness activity. We need this information to create a driving score.\n\nPlease, choose ",
                pageBoldText : "“OK”",
                lastPageText : " for \(appName) to grant us access to Motion & Fitness activity.",
                alertHeader  : "\(appName) Would Like to Access Your Motion & Fitness Activity",
                alertText    : "\n\nWe use motion sensors for evaluating your driving manner",
                buttonTexts  : ["Don’t Allow", "OK"],
                coloredButton: "OK"),
            PageHelper.createPage(
                    pageHeader   : "Attention Required!",
                    pageText     : "\n\nAs the next step, You will receive a popup to grant us rights to send you important notifications. You are always able to turn off notifications by categories in the App settings menu.\n\nPlease, choose ",
                    pageBoldText : "“Allow”",
                    lastPageText : " for \(appName) to keep you informed on important events.",
                    alertHeader  : "\(appName) Would Like to Send You Notifications",
                    alertText    : "\n\nNotifications may include alerts, sounds and icon badges. These can be configured in Settings",
                    buttonTexts  : ["Don’t Allow", "Allow"],
                    coloredButton: "Allow"),
            PageHelper.createPage(
                pageHeader   : "Attention Required!",
                pageText     : "\n\nYou will receive a popup shortly for \(appName) to have access to your location even when you are not using the app.\n\nFor the app to work properly\n",
                pageBoldText : "“Change to Always Allow”",
                lastPageText : "",
                alertHeader  : "Allow \(appName) to also access your location even when you are not using the app?",
                alertText    : "\n\nWe use location service for generating a driving score. By enabling “Always” on location, the app will be able to automatically determine when you have started and ended a drive",
                buttonTexts  : ["Keep Only While Using", "Change to Always Allow"],
                coloredButton: "Change to Always Allow")
        ]

        RPSettings.returnInstance().wizardPages = pages
        
        //Customization
        RPSettings.returnInstance().wizardNextButtonBgColor = UIColor.red
        RPSettings.returnInstance().wizardMaintextColor = UIColor.black
        RPSettings.returnInstance().wizardAlertBackgroundColor = UIColor.white
        RPSettings.returnInstance().wizardAlertTextColor = UIColor.green
        RPSettings.returnInstance().wizardAlertButtonTextColor = UIColor.blue
        RPSettings.returnInstance().wizardAlertActiveButtonTextColor = UIColor.red
        RPSettings.returnInstance().wizardAlertActiveButtonBgColor = UIColor.gray
        RPSettings.returnInstance().appName = "TelematicsApp"
        
        //Dark Scheme
        //RPSettings.returnInstance().wizardAlertBackgroundColor = UIColor.white
        //RPSettings.returnInstance().wizardAlertTextColor = UIColor.white
        //RPSettings.returnInstance().wizardAlertButtonTextColor = UIColor.white
        //RPSettings.returnInstance().wizardAlertActiveButtonTextColor = UIColor.white
        //RPSettings.returnInstance().wizardAlertActiveButtonBgColor = UIColor.white
        
        RPPermissionsWizard.returnInstance().launch(finish: { _ in
            RPEntry.initialize(withRequestingPermissions: true)
            
//FIXME: VIRTUAL DEVICE TOKEN REQUIRED!
            let token = NSString(string: "VIRTUAL_DEVICE_TOKEN") //REQUIRED!
            RPEntry.instance().virtualDeviceToken = token
            RPEntry.instance().trackingStateDelegate = self
            RPEntry.instance().locationDelegate = self
            RPEntry.instance().speedLimitDelegate = self
            RPEntry.instance().accuracyAuthorizationDelegate = self
            RPEntry.instance().lowPowerModeDelegate = self
            let options = launchOptions ?? [:]
            RPEntry.application(application, didFinishLaunchingWithOptions: options)

            if (ASIdentifierManager.shared().isAdvertisingTrackingEnabled) {
                RPEntry.instance().advertisingIdentifier = ASIdentifierManager.shared().advertisingIdentifier
            }
        })
        return true
    }
    
    // MARK: SDK Integration
    
    func applicationDidBecomeActive(_ application: UIApplication) {
        RPEntry.applicationDidBecomeActive(application)
    }
    
    func applicationDidEnterBackground(_ application: UIApplication) {
        RPEntry.applicationDidEnterBackground(application)
    }
    
    func applicationDidReceiveMemoryWarning(_ application: UIApplication) {
        RPEntry.applicationDidReceiveMemoryWarning(application)
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        RPEntry.applicationWillTerminate(application)
    }
    
    func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        RPEntry.application(application) {
            completionHandler(.newData)
        }
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }

    func application(_ application: UIApplication, handleEventsForBackgroundURLSession identifier: String, completionHandler: @escaping () -> Void) {
        RPEntry.application(application, handleEventsForBackgroundURLSession: identifier, completionHandler: completionHandler)
    }
    
    func addTag(_ status: RPTagStatus, tag: RPTag!, timestamp: Int) {
        let json: [String : Any?] = [
            "status": String(describing: status),
            "tag": String(data: tag.toJSON() as! Data, encoding: .utf8),
            "activationTime": timestamp
        ]

        //channel?.invokeMethod("onAddTag", arguments: json)
    }

    func deleteTag(_ status: RPTagStatus, tag: RPTag!, timestamp: Int) {
        let json: [String : Any?] = [
            "status": String(describing: status),
            "tag": String(data: tag.toJSON() as! Data, encoding: .utf8),
            "deactivationTime": timestamp
        ]

        //channel?.invokeMethod("onTagRemove", arguments: json)
    }

    func removeAll(_ status: RPTagStatus, timestamp: Int) {
        let json: [String : Any?] = [
            "status": String(describing: status),
            "time": timestamp
        ]

        //channel?.invokeMethod("onAllTagsRemove", arguments: json)
    }

    func getTags(_ status: RPTagStatus, tags: Any!, timestamp: Int) {
        let _tags = tags as? RPTags

        var strTags = [String]()

        _tags?.tags.forEach { element in
            let str = String(data: element.toJSON() as! Data, encoding: .utf8)!
            strTags.append(str)
        }

        let json: [String : Any?] = [
            "status": String(describing: status),
            "tags": strTags,
            "time": timestamp
        ]

        //channel?.invokeMethod("onGetTags", arguments: json)
    }
}


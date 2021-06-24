//
//  PageHelper.swift
//  DemoSwiftApp
//
//  Created by DATA MOTION PTE. LTD. on 09.06.21.
//  Copyright © 2021 DATA MOTION PTE. LTD. All rights reserved.
//

import Foundation
import RaxelPulse

class PageHelper {
    
    static func createPage(pageHeader: String, pageText: String, pageBoldText: String, lastPageText: String, alertHeader: String, alertText: String, buttonTexts: [String], coloredButton: String) -> RPPageTexts {
        let settings = RPSettings.returnInstance()
        //First Page
        let textSize : CGFloat = 16.0
        //let textHSize : CGFloat = 16.0
        let style = NSMutableParagraphStyle()
        style.alignment = NSTextAlignment.center
        let centerAttrs = [NSAttributedString.Key.paragraphStyle: style]
        let mainPageHeaderText = NSMutableAttributedString(string: pageHeader)
        let mainPageText = NSMutableAttributedString(string: pageText)
        let mainBoldPageText = NSMutableAttributedString(string: pageBoldText)
        let mainBottomPageText = NSMutableAttributedString(string: lastPageText)
        let attributesH: [NSAttributedString.Key : Any] = [
            .font: UIFont(name: "HelveticaNeue-Bold", size: textSize + 2.0)!
        ]
        let attributesT: [NSAttributedString.Key : Any] = [
            .font: UIFont(name: "HelveticaNeue", size: textSize)!
        ]
        mainPageText.addAttributes(
            attributesT,
            range: NSRange(location: 0, length: mainPageText.length))
        mainPageHeaderText.addAttributes(
            attributesH,
            range: NSRange(location: 0, length: mainPageHeaderText.length))
        mainPageHeaderText.append(mainPageText)
        mainBoldPageText.addAttributes(
            attributesH,
            range: NSRange(location: 0, length: mainBoldPageText.length))
        mainPageHeaderText.append(mainBoldPageText)
        mainBottomPageText.addAttributes(
            attributesT,
            range: NSRange(location: 0, length: mainBottomPageText.length))
        mainPageHeaderText.append(mainBottomPageText)
        let headerTC: [NSAttributedString.Key : Any] = [
            .foregroundColor: settings.wizardMaintextColor
        ]
        mainPageHeaderText.addAttributes(centerAttrs, range: NSMakeRange(0, mainPageHeaderText.length))
        mainPageHeaderText.addAttributes(headerTC, range: NSMakeRange(0, mainPageHeaderText.length))
        
        let mainAlertText = NSMutableAttributedString(string: alertHeader)
        let headerA: [NSAttributedString.Key : Any] = [
            .font: UIFont(name: "HelveticaNeue-Bold", size: textSize + 2.0)!
        ]
        let headerB: [NSAttributedString.Key : Any] = [
            .foregroundColor: settings.wizardAlertTextColor
        ]
        mainAlertText.addAttributes(
            headerA,
            range: NSRange(location: 0, length: mainAlertText.length))
        let alertT = NSMutableAttributedString(string: alertText)
        alertT.addAttributes(
            attributesT,
            range: NSRange(location: 0, length: alertT.length))
        mainAlertText.append(alertT)
        mainAlertText.addAttributes(
            headerB,
            range: NSRange(location: 0, length: mainAlertText.length))
        mainAlertText.addAttributes(centerAttrs, range: NSMakeRange(0, mainAlertText.length))
        var counter = 0
        var selected = 0
        var mainButtonsText: [NSMutableAttributedString] = [];
        for item in buttonTexts {
            if item == coloredButton {
                selected = counter
                let buttonActive = NSMutableAttributedString(string: item)
                let attributesFB: [NSAttributedString.Key : Any] = [
                    .foregroundColor: settings.wizardAlertActiveButtonTextColor,
                    .font: UIFont(name: "HelveticaNeue-Bold", size: textSize)!
                ]
                buttonActive.addAttributes(attributesFB, range: NSMakeRange(0, buttonActive.length))
                mainButtonsText.append(buttonActive)
            } else {
                counter += 1
                let buttonPassive = NSMutableAttributedString(string: item)
                let attributesSB: [NSAttributedString.Key : Any] = [
                    .foregroundColor: settings.wizardAlertButtonTextColor,
                    .font: UIFont(name: "HelveticaNeue", size: textSize)!
                ]
                buttonPassive.addAttributes(attributesSB, range: NSMakeRange(0, buttonPassive.length))
                mainButtonsText.append(buttonPassive)
            }
        }
        let page = RPPageTexts(pageText: mainPageHeaderText, alertText: mainAlertText, buttonsText: mainButtonsText, selected: selected)
        return page
    }
}

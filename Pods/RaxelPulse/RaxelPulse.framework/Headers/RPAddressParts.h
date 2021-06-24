//
//  RPAddressParts.h
//  RaxelPulse
//
//  Created by Sergey Emelyanov on 03/07/2019.
//  Copyright © 2020 Data Motion Pte. Ltd. All rights reserved.
//

#import "RPJSONSerializable.h"

/// Contains track info processed by server.
@interface RPAddressParts : NSObject<RPJSONSerializable> {
    
}

/// The country code of address.
@property (copy, nonatomic)   NSString  *countryCode;

/// The country of address.
@property (copy, nonatomic)   NSString  *country;

/// The county of address.
@property (copy, nonatomic)   NSString  *county;

/// The postal code of address.
@property (copy, nonatomic)   NSString  *postalCode;

/// The state of address.
@property (copy, nonatomic)   NSString  *state;

/// The city of address.
@property (copy, nonatomic)   NSString  *city;

/// The district of address.
@property (copy, nonatomic)   NSString  *district;

/// The street of address.
@property (copy, nonatomic)   NSString  *street;

/// The house of address.
@property (copy, nonatomic)   NSString  *house;

@end

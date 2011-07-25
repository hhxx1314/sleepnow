//
//  main.c
//  sleepnow
//
//  Created by Erica Sadun on 7/22/11.
//  Copyright 2011 Up To No Good, Inc. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#import <IOKit/IOKitLib.h>

Boolean dimDisplayNow(void);

Boolean dimDisplayNow(void) 
{
    io_registry_entry_t entry = IORegistryEntryFromPath(kIOMasterPortDefault, "IOService:/IOResources/IODisplayWrangler");
    if (!entry) return 0;
    
    OSErr err = IORegistryEntrySetCFProperty(entry, CFSTR("IORequestIdle"), kCFBooleanTrue);
    IOObjectRelease(entry);

    return (err == noErr);
}

int main (int argc, const char * argv[])
{
    dimDisplayNow();
    return 0;
}


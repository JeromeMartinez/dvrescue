/*  Copyright (c) MIPoPS. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-3-Clause license that can
 *  be found in the LICENSE file in the root of the source tree.
 */

#import <AVFoundation/AVFoundation.h>

@interface AVFCtlReceiver : NSObject

@property AVCaptureDevice *device;
@property NSFileHandle *output_file;
@property NSMutableData *output_data;

- (id) initWithDevice:(AVCaptureDevice*)theDevice;

- (void)  captureOutput:(AVCaptureOutput *)captureOutput
  didOutputSampleBuffer:(CMSampleBufferRef)videoFrame
         fromConnection:(AVCaptureConnection *)connection;

- (void)  captureOutput:(AVCaptureOutput *)captureOutput
    didDropSampleBuffer:(CMSampleBufferRef)videoFrame
         fromConnection:(AVCaptureConnection *)connection;

@end


@interface AVFCtl : NSObject

@property AVCaptureDevice *device;
@property AVCaptureSession *session;
@property AVCaptureVideoDataOutput *output;
@property AVFCtlReceiver *receiver;

@property AVCaptureDeviceTransportControlsPlaybackMode old_mode;
@property AVCaptureDeviceTransportControlsSpeed old_speed;

- (id) initWithDevice:(AVCaptureDevice*) theDevice;
- (void) dealloc;

- (NSString*) getDeviceName;

- (void) setPlaybackMode:(AVCaptureDeviceTransportControlsPlaybackMode)theMode speed:(AVCaptureDeviceTransportControlsSpeed) theSpeed;
- (void) createCaptureSessionWithOutputFileName:(NSString*) theFileName;
- (void) startCaptureSession;
- (void) stopCaptureSession;
@end

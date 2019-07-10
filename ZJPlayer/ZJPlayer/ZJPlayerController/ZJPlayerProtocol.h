//
//  ZJPlayerProtocol.h
//  ZJPlayer
//
//  Created by Jun Zhou on 2019/7/9.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ZJPlaybackState) {
    ZJPlaybackStateUnknown,
    ZJPlaybackStateStopped,
    ZJPlaybackStatePlaying,
    ZJPlaybackStatePaused,
    ZJPlaybackStateInterrupted,
    ZJPlaybackStateSeekingForward,
    ZJPlaybackStateSeekingBackward,
    ZJPlaybackStateReadyToPlay,
    ZJPlaybackStateFailed
};

typedef NS_OPTIONS(NSUInteger, ZJPlayerLoadState) {
    ZJPlayerLoadStateUnknown        = 0,
    ZJPlayerLoadStatePrepare        = 1 << 0,
    ZJPlayerLoadStatePlayable       = 1 << 1,
    ZJPlayerLoadStatePlaythroughOK  = 1 << 2,
    ZJPlayerLoadStateStalled        = 1 << 3,
};

typedef NS_ENUM(NSInteger, ZJPlayerFinishReason) {
    ZJPlayerFinishReasonPlaybackEnded,
    ZJPlayerFinishReasonPlaybackError,
    ZJPlayFinishReasonUserExited
};

typedef NS_ENUM(NSInteger, ZJPlayScalingMode) {
    ZJPlayerScalingModeNone,
    ZJPlayerScalingModeAspectFit,
    ZJPlayerScalingModeAspectFill,
    ZJPlayerScalingModeFill
};

NS_ASSUME_NONNULL_BEGIN

@protocol ZJPlayerProtocol <NSObject>

@property (nonatomic, assign)                   CGFloat volume;

@property (nonatomic, assign, getter=isMuted)   BOOL muted;

@property (nonatomic, assign)                   CGFloat rate;

@property (nonatomic, assign)                   NSTimeInterval seekTime;

@property (nonatomic, assign, readonly)         NSTimeInterval currentTime;

@property (nonatomic, assign, readonly)         NSTimeInterval totalTime;

@property (nonatomic, assign, readonly)         NSTimeInterval bufferTime;

@property (nonatomic, assign, readonly)         BOOL isPlaying;

@property (nonatomic, assign, readonly)         BOOL isPreparedToPlay;

@property (nonatomic, assign)                   BOOL shouldAutoPlay;

@property (nonatomic, strong)                   NSURL *assetURL;

@property (nonatomic, assign, readonly)         CGSize presentationSize;

@property (nonatomic, assign)                   ZJPlayScalingMode scalingMode;

@property (nonatomic, assign, readonly)         CGSize presentationSize;

@end

NS_ASSUME_NONNULL_END

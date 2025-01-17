//
//  YKWoodpeckerManager.h
//  YKWoodpecker
//
//  Created by Zim on 2018/10/25.


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString *const YKWoodpeckerManagerDidLaunchNotification;    /**< = @"YKWoodpeckerManagerDidLaunchNotification" */
extern NSString *const YKWoodpeckerManagerPluginsDidShowNotification;   /**< = @"YKWoodpeckerManagerPluginsDidShowNotification" */
extern NSString *const YKWoodpeckerManagerPluginsDidHideNotification;   /**< = @"YKWoodpeckerManagerPluginsDidHideNotification"*/

@class YKWScreenLog, YKWCmdCore;

@interface YSWoodpeckerManager : NSObject

/**
 Singleton.
 
 @return Singleton
 */
+ (YSWoodpeckerManager *)sharedInstance;

/**
Automatically open 'UI Check' tool on show.
*/
@property (nonatomic, assign) BOOL autoOpenUICheckOnShow;

/**
 Show woodpecker entrance.
 */
- (void)show;

/**
 Hide woodpecker entrance.
 */
- (void)hide;


// ----------------------------- Plugin Management -----------------------------

/**
 Safe mode, only safe plugins can be open, default is NO.
 */
@property (nonatomic, assign) BOOL safePluginMode;

/**
 Where the woodpecker icon's feet is, for getting/setting the woodpecker icon's position.
 */
@property (nonatomic, assign) CGPoint woodpeckerRestPoint;

/**
 Register a plugin.

 @param parasDic The plugin's parameters, see more in YKWPluginModel.h.
 @{
 @"isSafePlugin" : @(NO),
 @"pluginName" : @"",
 @"pluginInfo" : @"",
 @"pluginIconName" : @"",
 @"pluginCharIconText" : @"",
 @"pluginCharIconColorHex" : @"",
 @"pluginCategoryName" : @"",
 @"pluginClassName" : @"",
 @"pluginParameters" : @{}
 }
 @param index The plugin's position in its category, 0...N-1, or -1 for the last.

 */
- (void)registerPluginWithParameters:(NSDictionary *)parasDic atIndex:(NSInteger)index;

/**
 Register a plugin at the last.

 @param parasDic The plugin's parameters.
 */
- (void)registerPluginWithParameters:(NSDictionary *)parasDic;

/**
 Register a plugin category or change the position of a plugin category.

 @param pluginCategoryName Plugin category name.
 @param index Position to show the category, 0...N-1, or -1 for the last.
 */
- (void)registerPluginCategory:(NSString *)pluginCategoryName atIndex:(NSInteger)index;

/**
 Open a plugin.

 @param pluginName Plugin name.
 */
- (void)openPluginNamed:(NSString *)pluginName;

/**
 Open a plugin.

 @param pluginName Plugin name.
 @param parasDic Parameters to pass to the plugin.
 */
- (void)openPluginNamed:(NSString *)pluginName withParameters:(NSDictionary *)parasDic;


// ----------------------------- Crash Plugin -----------------------------

/**
 Register the crash handler for crash plugin to log crashes, the previous crash handler will be saved and called afterwards.
 */
+ (void)registerCrashHandler;

/// 获取crash日志
-(NSArray *)getCrashList;


// ----------------------------- Screen Log -----------------------------

/**
 The screen log of the singleton.
 */
@property (nonatomic, readonly) YKWScreenLog *screenLog;

/**
 Show log on the screen.

 @param logStr Log string.
 */
- (void)showLog:(NSString *)logStr;


// ----------------------------- Method Listening -----------------------------

/**
 Command source URL.
 */
@property (nonatomic, copy) NSString *cmdSourceUrl;

/**
 Command process core.
 */
@property (nonatomic, readonly) YKWCmdCore *cmdCore;

/**
 Show the command console.
 */
- (void)showConsole;

/**
 Prevent undefined-key-crash.
 */
- (void)addUndefinedKeyProtection;

+(void)logUpload:(NSDictionary *)dic;

+(NSArray *)shareItems;

@end

//
//  UZModule.h
//  UZEngine
//
//  Created by broad on 13-11-6.
//  Copyright (c) 2013年 APICloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum _KUZModuleErrorType {
    kUZModuleErrorTypeNormal = 0,
} KUZModuleErrorType;

typedef enum _KUZStringType {
    kUZStringType_JSON = 0,
    kUZStringType_TEXT,
} KUZStringType;

@class UZWebView;

@interface UZModule : NSObject

@property (nonatomic, readonly, weak) UZWebView *uzWebView;
@property (nonatomic, readonly, weak) UIViewController *viewController;

#pragma mark - lifeCycle
// 重载下面方法来执行初始化和释放操作
- (id)initWithUZWebView:(UZWebView *)webView;
- (void)dispose;

#pragma mark - ret event
/**
 执行回调方法返回数据
 
 @param cbId 回调函数id
 
 @param dataDict 返回的数据
 
 @param errDict 错误信息
 
 @param doDelete 执行回调后是否删除回调函数对象
 */
- (void)sendResultEventWithCallbackId:(NSInteger)cbId
                             dataDict:(NSDictionary *)dataDict
                              errDict:(NSDictionary *)errDict
                             doDelete:(BOOL)doDelete;

/**
 执行回调方法返回数据，回调函数里面的ret可以为字符串或JSON对象
 
 @param cbId 回调函数id
 
 @param dataString 返回的数据
 
 @param strType 返回数据类型
 
 @param errDict 错误信息
 
 @param doDelete 执行回调后是否删除函数对象
 */
- (void)sendResultEventWithCallbackId:(NSInteger)cbId
                           dataString:(NSString *)dataString
                           stringType:(KUZStringType)strType
                              errDict:(NSDictionary *)errDict
                             doDelete:(BOOL)doDelete;

/**
 删除不再使用的回调函数对象
 
 @param cbId 要删除的回调函数id
 */
- (void)deleteCallback:(NSInteger)cbId;

/**
 在当前页面执行一段javascript代码
 
 @param js 要执行的javascript代码
 */
- (void)evalJs:(NSString *)js;

#pragma mark - utility methods

/**
 将包含自定义协议的路径转换成绝对路径
 
 @param urlStr 源路径，可能包含APICloud自定义协议路径，如'fs://', 'widget://', 'cache://'等
 
 @return 转换后的绝对路径
 */
- (NSString *)getPathWithUZSchemeURL:(NSString *)urlStr;

/**
 获取指定窗口对象
 
 @param name 窗口名字
 
 @return 窗口对象
 */
- (UIView *)getViewByName:(NSString *)name;

/**
 在指定窗口上面添加视图
 
 @param fixedOn 目标窗口名字，默认为主窗口名字
 
 @param fixed 视图是否固定，为NO时跟随目标窗口内容滚动而滚动
 */
- (void)addSubview:(UIView *)view fixedOn:(NSString *)fixedOn fixed:(BOOL)fixed;

/**
 从加密的key.xml文件中获取解密后的数据
 
 @param key 加密字段
 
 @return 解密后的数据，如果获取失败则返回nil
 */
- (NSString *)securityValueForKey:(NSString *)key;
@end
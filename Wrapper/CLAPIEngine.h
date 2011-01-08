//
//  CLAPIEngine.h
//  Cloud
//
//  Created by Nick Paulson on 7/20/10.
//  Copyright 2010 Linebreak. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLAPIEngineDelegate.h"
#import "CLAPIEngineConstants.h"
#import "CLWebItem.h"
#import "CLAccount.h"

@interface CLAPIEngine : NSObject {
	NSString *_email;
	NSString *_password;
	id<CLAPIEngineDelegate> _delegate;
	
	NSMutableSet *_transactions;
	
	BOOL _clearsCookies;
}

@property (nonatomic, readwrite, copy) NSString *email;
@property (nonatomic, readwrite, copy) NSString *password;
@property (nonatomic, readwrite, assign) id<CLAPIEngineDelegate> delegate;
@property (nonatomic, readwrite, retain) NSMutableSet *transactions;

//This property makes the engine clear the cookies before making a new connection.  
//This can be helpful when credentials are "stuck."
@property (nonatomic, readwrite, assign) BOOL clearsCookies;

- (id)initWithDelegate:(id<CLAPIEngineDelegate>)aDelegate;
+ (CLAPIEngine *)engine;
+ (CLAPIEngine *)engineWithDelegate:(id<CLAPIEngineDelegate>)aDelegate;

//Returns whether or not the email/password fields are complete.
- (BOOL)isReady;

//Cancel the connection with identifier
- (void)cancelConnection:(NSString *)connectionIdentifier;

//Cancel all connections
- (void)cancelAllConnections;

- (id)userInfoForConnectionIdentifier:(NSString *)identifier;

- (NSString *)createAccountWithEmail:(NSString *)accountEmail password:(NSString *)accountPassword userInfo:(id)userInfo;
- (NSString *)changePrivacyOfItem:(CLWebItem *)webItem toPrivate:(BOOL)isPrivate userInfo:(id)userInfo;
- (NSString *)changeNameOfItem:(CLWebItem *)webItem toName:(NSString *)newName userInfo:(id)userInfo;
- (NSString *)getAccountInformationWithUserInfo:(id)userInfo;
- (NSString *)getItemInformation:(CLWebItem *)item userInfo:(id)userInfo;
- (NSString *)getItemInformationAtURL:(NSURL *)itemURL userInfo:(id)userInfo;
- (NSString *)bookmarkLinkWithURL:(NSURL *)url name:(NSString *)name userInfo:(id)userInfo;
- (NSString *)uploadFileWithName:(NSString *)fileName fileData:(NSData *)fileData userInfo:(id)userInfo;
- (NSString *)deleteItem:(CLWebItem *)webItem userInfo:(id)userInfo;
- (NSString *)deleteItemAtHref:(NSURL *)href userInfo:(id)userInfo;
- (NSString *)getItemListStartingAtPage:(NSInteger)pageNumStartingAtOne itemsPerPage:(NSInteger)perPage userInfo:(id)userInfo;
- (NSString *)getItemListStartingAtPage:(NSInteger)pageNumStartingAtOne ofType:(CLWebItemType)type itemsPerPage:(NSInteger)perPage userInfo:(id)userInfo;
- (NSString *)getItemListStartingAtPage:(NSInteger)pageNumStartingAtOne ofType:(CLWebItemType)type itemsPerPage:(NSInteger)perPage showOnlyItemsInTrash:(BOOL)showOnlyItemsInTrash userInfo:(id)userInfo;

@end

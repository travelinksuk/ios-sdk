//
//  LoginViewModel.swift
//  SampleAppSwift
//
//  Created by Synerise
//  Copyright (c) 2018 Synerise. All rights reserved.
//

import Foundation
import FBSDKCoreKit
import FBSDKLoginKit
import SyneriseSDK

protocol LoginViewModelDelegate: class {
    func userLoginSuccess(_ loginViewModel: LoginViewModel, response: Any)
    func userLoginError(_ loginViewModel: LoginViewModel, error: Error)
}

class LoginViewModel {

    var coordinator: SigningCoordinator?
    weak var delegate: LoginViewModelDelegate?

    var userLoginFormViewModel: UserLoginFormViewModel = {
        let login = "krzysztof.kurzawa@synerise.com"
        let password = "testPass12345!"
        let loginType = UserLoginFormViewModel.LoginType.email

        let userLoginFormViewModel = UserLoginFormViewModel(login: login, password: password, loginType: loginType)

        return userLoginFormViewModel
    }()

    // MARK: - Init

    init() {
        setup()
    }

    // MARK: - Public

    func createNewAccount() {
        coordinator?.navigateToRegistration()
    }
    
    func authenticateByFacebookToken(onSuccess: @escaping (() -> ())) {
        guard let facebookToken = FBSDKAccessToken.current()?.tokenString else {
            return
        }
        
        Client.authenticate(facebookToken: facebookToken, success: { (success) in
            onSuccess()
        }, failure: nil)
    }

    // MARK: - Private

    func create() {
        coordinator?.startWithRegistration()
    }

    private func setup() {
        userLoginFormViewModel.invokeOnSuccess { response in
            self.delegate?.userLoginSuccess(self, response: response)
        }

        userLoginFormViewModel.invokeOnError { error in
            self.delegate?.userLoginError(self, error: error)
        }
    }
}
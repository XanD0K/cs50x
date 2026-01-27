document.addEventListener('DOMContentLoaded', function() {
    // Update 'total' value after user enters share number
    // Used in 'buy.html' and 'sell.html'
    const sharesInput = document.querySelector('input[name="shares"]')
    if (sharesInput) {
        sharesInput.addEventListener('input', function() {
        let shares = Number(this.value) || 0;
        let price = Number(this.dataset.price);
        let totalCostValue = shares * price;

        let totalCostText = document.getElementById('total_cost');
        let totalIncomeText = document.getElementById('total_income');

        // buy.hmtl
        if (totalCostText) {
            totalCostText.textContent = '$' + totalCostValue.toFixed(2);
        }
        // sell.html
        else if (totalIncomeText) {
            totalIncomeText.textContent = '$' + totalCostValue.toFixed(2);
        }
        })
    }


    // Redirect 'animation'
    const dotsList = ["", ".", "..", "..."];
    let index = 0;

    const dots = document.getElementById('dots');
    const animation = setInterval(function() {
        dots.textContent = dotsList[index];
        index = (index + 1) % dotsList.length;
    }, 300)

    setTimeout(function() {
        clearInterval(animation);
    }, 3000);


    // Display

    // JS Validations
    // Used in 'login.html'
    let loginButton = document.getElementById('login_button');
    if(loginButton ) {
        let usernameText = document.getElementById('username_error_message');
        let passwordText = document.getElementById('password_error_message');
        loginButton.addEventListener('click', function(event) {
            let username = document.querySelector('input[name="username"]').value;
            let password = document.querySelector('input[name="password"]').value;

            usernameText.innerHTML = '';
            passwordText.innerHTML = '';

            if (!username) {
                event.preventDefault();
                usernameText.innerHTML = 'Insert username';
            }
            if (!password) {
                event.preventDefault();
                passwordText.innerHTML = 'Insert password';
            }
        })
    }

    
    // Used in 'new_password.html'
    let newPasswordButton = document.getElementById('new_password_button');
    if(newPasswordButton ) {
        let usernameText = document.getElementById('username_error_message');
        let securityAnswerText = document.getElementById('security_answer_error_message');
        newPasswordButton.addEventListener('click', function(event) {
            let username = document.querySelector('input[name="username"]').value;
            let securityAnswer = document.querySelector('input[name="security_answer"]').value;

            usernameText.innerHTML = '';
            securityAnswerText.innerHTML = '';

            if (!username) {
                event.preventDefault();
                usernameText.innerHTML = 'Insert username';
            }
            if (!securityAnswer) {
                event.preventDefault();
                securityAnswerText.innerHTML = 'Insert security answer';
            }
        })
    }

    // Used in 'new_password_2.html'
    let newPassword2Button = document.getElementById('new_password_button_2');
    if(newPassword2Button ) {
        let passwordText = document.getElementById('password_error_message');
        let confirmationText = document.getElementById('confirmation_error_message');
        let matchText = document.getElementById('match_error_message');
        newPassword2Button.addEventListener('click', function(event) {
            let password = document.querySelector('input[name="password"]').value;
            let confirmation = document.querySelector('input[name="confirmation"]').value;

            passwordText.innerHTML = '';
            confirmationText.innerHTML = '';
            matchText.innerHTML = '';

            if (!password) {
                event.preventDefault();
                passwordText.innerHTML = 'Insert password';
            }
            else if (password.length < 8) {
                event.preventDefault();
                passwordText.innerHTML = 'At least 8 characters';
            }
            if (!confirmation) {
                event.preventDefault();
                confirmationText.innerHTML = 'Insert password again';
            }
            if (password !== confirmation) {
                event.preventDefault();
                matchText.innerHTML = 'Passwords don\'t match';
            }
        })
    }

    // Used in 'money.html'
    let moneyButton = document.getElementById('add_money_button');
    if(moneyButton) {
        let moneyText = document.getElementById('money_error_message');
        moneyButton.addEventListener('click', function(event) {
            let moneyInput = document.querySelector('input[name="money"]').value;
            let money = Number(moneyInput);

            if(!moneyInput) {
                event.preventDefault();
                moneyText.innerHTML = 'Insert a value';
            }

            else if (isNaN(money) || money < 1 || money > 10000) {
                event.preventDefault();
                moneyText.innerHTML = 'Amount must be between $1 and $10,000';
            }

            else {
                moneyText.innerHTML = '';
            }
        })
    }

    // Used in 'quote.html', 'buy.html' (first configuration)
    let searchButton = document.getElementById('search_button');
    if(searchButton) {
        let searchText = document.getElementById('search_error_message');
        searchButton.addEventListener('click', function(event) {
            let symbol = document.querySelector('input[name="symbol"]').value;

            if(!symbol) {
                event.preventDefault();
                searchText.innerHTML = 'Insert a stock symbol';
            }

            else {
                searchText.innerHTML = '';
            }
        })
    }

    // Used in 'buy.html' (second configuration)
    let buyButton = document.getElementById('buy_button');
    if(buyButton) {
        let buyText = document.getElementById('buy_error_message');
        buyButton.addEventListener('click', function(event) {
            let sharesInput = document.querySelector('input[name="shares"]').value;
            let shares = Number(sharesInput);

            if(!sharesInput) {
                event.preventDefault();
                buyText.innerHTML = 'Insert a number of shares to buy';
            }

            else if (isNaN(shares) || shares < 1) {
                event.preventDefault();
                buyText.innerHTML = 'Enter a valid number of shares';
            }

            else {
                buyText.innerHTML = '';
            }
        })
    }

    // Used in sell.html
    let selectButton = document.getElementById('select_button');
    if(selectButton) {
        let selectText = document.getElementById('select_error_message');
        selectButton.addEventListener('click', function(event) {
            let symbol = document.querySelector('select[name="symbol"]').value;

            if(!symbol) {
                event.preventDefault();
                selectText.innerHTML = 'Select a stock symbol';
            }

            else {
                selectText.innerHTML = '';
            }
        })
    }

    let sellButton = document.getElementById('sell_button');
    if(sellButton) {
        let sellText = document.getElementById('sell_error_message');
        sellButton.addEventListener('click', function(event) {
            let sharesInput = document.querySelector('input[name="shares"]').value;
            let shares = Number(sharesInput);
            let totalShares = Number(document.querySelector('input[name="shares"]').getAttribute('max'));

            if(!sharesInput) {
                event.preventDefault();
                sellText.innerHTML = 'Insert a value';
            }
            else if (isNaN(shares) || shares < 1) {
                event.preventDefault();
                sellText.innerHTML = 'Enter a valid number of shares';
            }
            else if (shares > totalShares) {
                event.preventDefault();
                sellText.innerHTML = 'You don\'t have enough shares';
            }
            else {
                sellText.innerHTML = '';
            }
        })
    }
})


// TODO: Create a reusable code for all JS validations to remove redundancies

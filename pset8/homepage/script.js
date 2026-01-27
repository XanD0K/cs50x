// "Loading" animation function
const currentLoading = ["Loading", "Loading.", "Loading..", "Loading..."];
let index = 0;
let timer;
function loadingAnimation() {
    document.querySelector('#greeting').innerHTML = currentLoading[index];
    index += 1;
    if (index >= 4) {
        index = 0;
    }
}

// Greetings and Geolocation
if (document.querySelector('#greeting-form')) {
    document.querySelector('#greeting-form').addEventListener('submit', function(event) {
        event.preventDefault(); // Prevents 'form' from reloading the page
        let name = document.querySelector('#name').value;
        document.querySelector('#greeting').innerHTML = 'Loading...';
        index = 0;
        timer = setInterval(loadingAnimation, 500);
        navigator.geolocation.getCurrentPosition(function(location) {
            let lat = location.coords.latitude;
            let lon = location.coords.longitude;
            let url = `https://nominatim.openstreetmap.org/reverse?format=json&lat=${lat}&lon=${lon}`;
            fetch(url)
                .then(response => response.json())
                .then(data => {
                    clearInterval(timer);
                    if(data.address && data.address.country){
                        let country = data.address.country;
                        document.querySelector('#greeting').innerHTML = name.trim()
                            ? `Hello, ${name}! Thanks for accessing this website from ${country}!`
                            : `Hello, whoever you are! Feel free to access this website from ${country}!`;
                    }
                    else {
                        document.querySelector('#greeting').innerHTML = name.trim()
                            ? `Hello, ${name}! Feel free to access this website from wherever you are!`
                            : `Hello, whoever you are! Feel free to access this website from wherever you are!`;
                    }
                })
                .catch(error => {
                    clearInterval(timer);
                    document.querySelector('#greeting').innerHTML = name.trim()
                        ? `Hello, ${name}! Feel free to access this website from wherever you are!`
                        : `Hello, whoever you are! Feel free to access this website from wherever you are!`;
                });
        },
        function(error) {
            clearInterval(timer);
            document.querySelector('#greeting').innerHTML = name.trim()
            ? `Hello, ${name}! Feel free to access this website wherever you are!`
            : `Hello, whoever you are! Feel free to access this website wherever you are!`;
        });
    });
}

// Changing theme (dark/light)
const navbar = document.querySelector('.navbar');
const lightButton = document.querySelector('#light-mode');
const darkButton = document.querySelector('#dark-mode');
// Check user's default theme
let theme = localStorage.getItem('theme');
if (theme === null) {
    theme = window.matchMedia('(prefers-color-scheme: light)').matches ? 'light' : 'dark';
}
if (theme === 'light') {
    document.body.classList.add('light-mode');
    navbar.setAttribute('data-bs-theme', 'light');
    navbar.classList.remove('bg-dark');
    navbar.classList.add('bg-light');
    lightButton.classList.add('toggled');
    darkButton.classList.remove('toggled');
}
else {
    document.body.classList.remove('light-mode');
    navbar.setAttribute('data-bs-theme', 'dark');
    navbar.classList.remove('bg-light');
    navbar.classList.add('bg-dark');
    darkButton.classList.add('toggled');
    lightButton.classList.remove('toggled');
}
// Sun and Moon buttons
if(lightButton && darkButton) {
    lightButton.addEventListener('click', function(event) {
        document.body.classList.add('light-mode');
        navbar.setAttribute('data-bs-theme', 'light');
        navbar.classList.remove('bg-dark');
        navbar.classList.add('bg-light');
        lightButton.classList.add('toggled');
        darkButton.classList.remove('toggled');
        localStorage.setItem('theme', 'light');
    });
    darkButton.addEventListener('click', function(event) {
        document.body.classList.remove('light-mode');
        navbar.setAttribute('data-bs-theme', 'dark');
        navbar.classList.remove('bg-light');
        navbar.classList.add('bg-dark');
        darkButton.classList.add('toggled');
        lightButton.classList.remove('toggled');
        localStorage.setItem('theme', 'dark');
    });
}


// Set player/iframe. Provided by YT's documentation
let player;
function onYouTubeIframeAPIReady() {
    player = new YT.Player('yt-player', {
        events: {
            'onReady': onPlayerReady
        }
    });
}

function onPlayerReady(event) {
    event.target.setVolume(40);  // Setting initial volume
    const toggleButton = document.getElementById('music-toggle');
    toggleButton.addEventListener('click', togglePlayPause);
}

// Controlling play and pause buttons
function togglePlayPause() {
    const button = document.querySelector('#music-toggle i');
    if (player.getPlayerState() === YT.PlayerState.PLAYING) {
        player.pauseVideo();
        button.classList.remove('fa-pause');
        button.classList.add('fa-play');
    }
    else {
        player.playVideo();
        button.classList.remove('fa-play');
        button.classList.add('fa-pause');
    }
}

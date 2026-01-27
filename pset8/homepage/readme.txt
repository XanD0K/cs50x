This file will list all HTML and CSS used, besides giving a deeper explanation of what I did, so that '.specification.txt' meets pset's requirements.

1. HTML
<a>
<br>
<button>
<div>
<figure>/<figcaption>
<footer>
<h1><h2><h4>
<header>
<iframe>
<img>
<input>
<link>
<main>
<meta> Added after watching week9's lecture, to make the page more user friendly to mobible users
<p>
<script>
<section>
<ul>/<li>

2. CSS
background:
background-color:
border:/border-top:
border-radius:
box-shadow:
color:
display:
flex-direction:
flex-wrap:
font-size:
font-weight:
gap:
height:
list-style-type:
margin:/margin-bottom:/margin-top:
max-width:
object-fit:
overflow:
padding:/padding-top:
text-align:
text-decoration:
transform:
transition:
width:

3. Bootstrap
Navbar
A collapsile menu to navigate throughout all pages, with the option to switch theme.
It stays locked on the top of the page and transform in a "hamburger" button on small screens.

4. JavaScript
4.1 Greetings and Geolocation
Get's user's name and location and output a personalized greetings message.
If user didn't input a name there will be a specific message to that.
If user didn't allow location track, or if the API didn't work, or if it worked, but with no valid result, there will also be messages for that.
I also implemented a "Loading" animation, to improve user's experience.

4.2 Theme Switch
Will switch between light and dark theme, with two buttons in the navbar (sun and moon icons).
It works in two ways:
First it gets user's system/browser theme. That will be assigned as the default theme in 'localStorage'.
Second, there are two buttons (sun and moon) in navbar to switch theme.
For that, used CSS classes and selectors to assign "light-mode" to <body> tag, which will affect all related elements.


Sites used:
https://getbootstrap.com/docs/5.3/components/navbar/
https://cssgradient.io/
https://fontawesome.com/
https://www.w3schools.com/jsref/api_geolocation.asp
https://nominatim.org/release-docs/latest/api/Reverse/
https://squoosh.app/ - Used to convert all images to .webp format

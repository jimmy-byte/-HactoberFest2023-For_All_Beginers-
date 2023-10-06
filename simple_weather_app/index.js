const apiKey = "f5b507f8fba96d93ae2ef7b15c3b5c91";
const searchBox = document.querySelector(".search input");
const searchBtn = document.querySelector(".search button");
const weatherIcon = document.querySelector(".weather-icon");


async function checkWeather(city){
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`;
    const response = await fetch(apiUrl);
    let data = await response.json();

    document.querySelector(".city").innerHTML = data.name;
    document.querySelector(".temp").innerHTML = data.main.temp + " °C";
    document.querySelector(".humidity").innerHTML = data.main.humidity + " %";
    document.querySelector(".wind").innerHTML = data.wind.speed + " km/h";

    if(data.weather[0].main === "Clouds"){
        weatherIcon.src = "images/clouds.png";
    }
    else if(data.weather[0].main==="Clear"){
        weatherIcon.src = "images/clear.png";
    }
    else if(data.weather[0].main === "Drizzle"){
        weatherIcon.src = "images/drizzle.png"
    }
    else if(data.weather[0].main === "Mist"){
        weatherIcon.src = "images/mist.png"
    }

    document.querySelector(".weather").style.display = "block";
    
}

searchBtn.addEventListener("click", ()=>{
    checkWeather(searchBox.value);
})

document.querySelector(".search input").addEventListener("keydown", function(event){
    if(event.key === "Enter"){
        checkWeather(searchBox.value);
    }
})

function mainfunction()
{
	var l = document.getElementById("location_in").value;

	$.getJSON("https://api.openweathermap.org/data/2.5/weather?q=" + l + "&units=si&appid=6ba76e81b921b55d5f15b37ba2a2e089",function(data)
	{
		console.log(data);
		var icon = "https://openweathermap.org/img/w/" + data.weather[0].icon + ".png";
		var temp = Math.round(data.main.temp-273);
		var weather = data.weather[0].main;
		change_background(weather);
		change_background2(weather);
		var description = data.weather[0].description;
		var temp_min = data.main.temp_min-273;
		var temp_min_r = temp_min.toFixed(2);
		var temp_max = data.main.temp_max-273;
		var temp_max_r = temp_max.toFixed(2);
		var pressure = data.main.pressure;
		var humidity = data.main.humidity;
		var visiblity = Math.floor(data.visibility/1000);
		var wind_speed = data.wind.speed; 

		document.getElementById("temp").innerHTML=temp;
		document.getElementById("icon").src=icon;
		if(weather == "Thunderstorm")
		{
			document.getElementById("weather").innerHTML="thunder";	
		}
		else
		{
			document.getElementById("weather").innerHTML=weather;
		}
		document.getElementById("description").innerHTML=description;
		document.getElementById("temp_max").innerHTML=temp_max_r;
		document.getElementById("temp_min").innerHTML=temp_min_r;
		document.getElementById("pressure").innerHTML=pressure;
		document.getElementById("humidity").innerHTML=humidity;
		document.getElementById("visiblity").innerHTML=visiblity;
		document.getElementById("wind_speed").innerHTML=wind_speed;
	});
}

function autofill1()
{
	var l = document.getElementById("location_in").value;

	$.getJSON("https://api.mapbox.com/geocoding/v5/mapbox.places/" + l + ".json?access_token=pk.eyJ1IjoibTBoYW5yYW0iLCJhIjoiY2s4MnExMXh0MGVjbDNlb2d0c2xmNGI3dyJ9.yU3IL7B_JxbdFhZOF5_E_w",function(coordinates)
	{
		console.log(coordinates);

		var lat = coordinates.features[0].center[1];
		var lon = coordinates.features[0].center[0];

		document.getElementById("latitude").value=lat;
		document.getElementById("longitude").value=lon;
	});
}

function autofill2()
{
	var lat = document.getElementById("latitude").value;
	var lon = document.getElementById("longitude").value;

	$.getJSON("https://api.mapbox.com/geocoding/v5/mapbox.places/" + lon + "," + lat + ".json?access_token=pk.eyJ1IjoibTBoYW5yYW0iLCJhIjoiY2s4MnExMXh0MGVjbDNlb2d0c2xmNGI3dyJ9.yU3IL7B_JxbdFhZOF5_E_w",function(place)
	{
		console.log(place);

		var l = place.features[0].context[1].text;

		document.getElementById("location_in").value=l;
	});

}

function change_background(weather_description)
{
		if(weather_description=="Clouds")
		{
			document.getElementById("changebackground").src="clouds.gif";
		}
		else if(weather_description=="Haze")
		{
			document.getElementById("changebackground").src="haze.gif";
		}
		else if(weather_description=="Thunderstorm")
		{
			document.getElementById("changebackground").src="thunderstorm.gif";
		}
		else if(weather_description=="Drizzle")
		{
			document.getElementById("changebackground").src="drizzle.gif";
		}
		else if(weather_description=="Rain")
		{
			document.getElementById("changebackground").src="rain.gif";
		}
		else if(weather_description=="Snow")
		{
			document.getElementById("changebackground").src="snow.gif";
		}
		else if(weather_description=="Mist")
		{
			document.getElementById("changebackground").src="fog.gif";
		}
		else if(weather_description=="Smoke")
		{
			document.getElementById("changebackground").src="smoke.gif";
		}
		else if(weather_description=="Dust")
		{
			document.getElementById("changebackground").src="dust.gif";
		}
		else if(weather_description=="Fog")
		{
			document.getElementById("changebackground").src="fog.gif";
		}
		else if(weather_description=="Sand")
		{
			document.getElementById("changebackground").src="sand.gif";
		}
		else if(weather_description=="Ash")
		{
			document.getElementById("changebackground").src="dust.gif";
		}
		else if(weather_description=="Squall")
		{
			document.getElementById("changebackground").src="fog.gif";
		}
		else if(weather_description=="Tornado")
		{
			document.getElementById("changebackground").src="tornado.gif";
		}
		else if(weather_description=="Clear")
		{
			document.getElementById("changebackground").src="clear2.gif";
		}
}

function change_background2(weather_description)
{
		if(weather_description=="Clouds")
		{
			document.getElementById("changebackground2").src="clouds.gif";
		}
		else if(weather_description=="Haze")
		{
			document.getElementById("changebackground2").src="haze.gif";
		}
		else if(weather_description=="Thunderstorm")
		{
			document.getElementById("changebackground2").src="thunderstorm.gif";
		}
		else if(weather_description=="Drizzle")
		{
			document.getElementById("changebackground2").src="drizzle.gif";
		}
		else if(weather_description=="Rain")
		{
			document.getElementById("changebackground2").src="rain.gif";
		}
		else if(weather_description=="Snow")
		{
			document.getElementById("changebackground2").src="snow.gif";
		}
		else if(weather_description=="Mist")
		{
			document.getElementById("changebackground2").src="fog.gif";
		}
		else if(weather_description=="Smoke")
		{
			document.getElementById("changebackground2").src="smoke.gif";
		}
		else if(weather_description=="Dust")
		{
			document.getElementById("changebackground2").src="dust.gif";
		}
		else if(weather_description=="Fog")
		{
			document.getElementById("changebackground2").src="fog.gif";
		}
		else if(weather_description=="Sand")
		{
			document.getElementById("changebackground2").src="sand.gif";
		}
		else if(weather_description=="Ash")
		{
			document.getElementById("changebackground2").src="dust.gif";
		}
		else if(weather_description=="Squall")
		{
			document.getElementById("changebackground2").src="fog.gif";
		}
		else if(weather_description=="Tornado")
		{
			document.getElementById("changebackground2").src="tornado.gif";
		}
		else if(weather_description=="Clear")
		{
			document.getElementById("changebackground2").src="clear2.gif";
		}
}

function forecast()
{
	var l = document.getElementById("location_in").value;

	$.getJSON("https://api.openweathermap.org/data/2.5/forecast?q=" + l + "&appid=6ba76e81b921b55d5f15b37ba2a2e089",function(forecast)
	{
		console.log(forecast);

		var today = new Date();
		var today1 = new Date(today);
		today1.setDate(today1.getDate() );
		var dd = String(today1.getDate()).padStart(2,'0');
		var mm = String(today1.getMonth()+1).padStart(2,'0');
		var yyyy = today1.getFullYear();
		today1 = dd + '/' + mm + '/' + yyyy;
		
		var today = new Date();
		var today2 = new Date(today);
		today2.setDate(today2.getDate() + 1);
		var dd = String(today2.getDate()).padStart(2,'0');
		var mm = String(today2.getMonth()+1).padStart(2,'0');
		var yyyy = today2.getFullYear();
		today2 = dd + '/' + mm + '/' + yyyy;
		
		var today = new Date();
		var today3 = new Date(today);
		today3.setDate(today3.getDate() + 2);
		var dd = String(today3.getDate()).padStart(2,'0');
		var mm = String(today3.getMonth()+1).padStart(2,'0');
		var yyyy = today3.getFullYear();
		today3 = dd + '/' + mm + '/' + yyyy;

		var today = new Date();
		var today4 = new Date(today);
		today4.setDate(today4.getDate() + 3);
		var dd = String(today4.getDate()).padStart(2,'0');
		var mm = String(today4.getMonth()+1).padStart(2,'0');
		var yyyy = today4.getFullYear();
		today4 = dd + '/' + mm + '/' + yyyy;

		var today = new Date();
		var today5 = new Date(today);
		today5.setDate(today5.getDate() + 4);
		var dd = String(today5.getDate()).padStart(2,'0');
		var mm = String(today5.getMonth()+1).padStart(2,'0');
		var yyyy = today5.getFullYear();
		today5 = dd + '/' + mm + '/' + yyyy;

		 var temp_1 = Math.floor(forecast.list[0].main.temp-272);
		 var weather_1 = forecast.list[0].weather[0].main;
		 var description_1 = forecast.list[0].weather[0].description;
		 var temp_min_1 = Math.floor(forecast.list[0].main.temp_min-272);
		 var temp_max_1 = Math.floor(forecast.list[0].main.temp_max-272);
	     var pressure_1 = forecast.list[0].main.pressure;
		 var humidity_1 = forecast.list[0].main.humidity;
		 var wind_speed_1 = forecast.list[0].wind.speed; 

		 var temp_2 = Math.floor(forecast.list[0].main.temp-272);
		 var weather_2 = forecast.list[0].weather[0].main;
		 var description_2 = forecast.list[0].weather[0].description;
		 var temp_min_2 = Math.floor(forecast.list[0].main.temp_min-272);
		 var temp_max_2 = Math.floor(forecast.list[0].main.temp_max-272);
	     var pressure_2 = forecast.list[0].main.pressure;
		 var humidity_2 = forecast.list[0].main.humidity;
		 var wind_speed_2 = forecast.list[0].wind.speed;
		 
		 var temp_3 = Math.floor(forecast.list[16].main.temp-272);
		 var weather_3 = forecast.list[16].weather[0].main;
		 var description_3 = forecast.list[16].weather[0].description;
		 var temp_min_3 = Math.floor(forecast.list[16].main.temp_min-272);
		 var temp_max_3 = Math.floor(forecast.list[16].main.temp_max-272);
	     var pressure_3 = forecast.list[16].main.pressure;
		 var humidity_3 = forecast.list[16].main.humidity;
		 var wind_speed_3 = forecast.list[16].wind.speed; 

		 var temp_4 = Math.floor(forecast.list[24].main.temp-272);
		 var weather_4 = forecast.list[24].weather[0].main;
		 var description_4 = forecast.list[24].weather[0].description;
		 var temp_min_4 = Math.floor(forecast.list[24].main.temp_min-272);
		 var temp_max_4 = Math.floor(forecast.list[24].main.temp_max-272);
	     var pressure_4 = forecast.list[24].main.pressure;
		 var humidity_4 = forecast.list[24].main.humidity;
		 var wind_speed_4 = forecast.list[24].wind.speed; 

		 var temp_5 = Math.floor(forecast.list[32].main.temp-272);
		 var weather_5 = forecast.list[32].weather[0].main;
		 var description_5 = forecast.list[32].weather[0].description;
		 var temp_min_5 = Math.floor(forecast.list[32].main.temp_min-272);
		 var temp_max_5 = Math.floor(forecast.list[32].main.temp_max-272);
	     var pressure_5 = forecast.list[32].main.pressure;
		 var humidity_5 = forecast.list[32].main.humidity;
		 var wind_speed_5 = forecast.list[32].wind.speed; 

		document.getElementById("date1").innerHTML=today1;
		document.getElementById("date2").innerHTML=today2;
		document.getElementById("date3").innerHTML=today3;
		document.getElementById("date4").innerHTML=today4;
		document.getElementById("date5").innerHTML=today5;
		
		document.getElementById("temp_1").innerHTML=temp_1;
		document.getElementById("weather_1").innerHTML=weather_1;
		document.getElementById("temp_max_1").innerHTML=temp_max_1;
		document.getElementById("temp_min_1").innerHTML=temp_min_1;
		document.getElementById("pressure_1").innerHTML=pressure_1;
		document.getElementById("humidity_1").innerHTML=humidity_1;
		document.getElementById("wind_speed_1").innerHTML=wind_speed_1;

		document.getElementById("temp_2").innerHTML=temp_2;
		document.getElementById("weather_2").innerHTML=weather_2;
		document.getElementById("temp_max_2").innerHTML=temp_max_2;
		document.getElementById("temp_min_2").innerHTML=temp_min_2;
		document.getElementById("pressure_2").innerHTML=pressure_2;
		document.getElementById("humidity_2").innerHTML=humidity_2;
		document.getElementById("wind_speed_2").innerHTML=wind_speed_2;

		document.getElementById("temp_3").innerHTML=temp_3;
		document.getElementById("weather_3").innerHTML=weather_3;
		document.getElementById("temp_max_3").innerHTML=temp_max_3;
		document.getElementById("temp_min_3").innerHTML=temp_min_3;
		document.getElementById("pressure_3").innerHTML=pressure_3;
		document.getElementById("humidity_3").innerHTML=humidity_3;
		document.getElementById("wind_speed_3").innerHTML=wind_speed_3;

		document.getElementById("temp_4").innerHTML=temp_4;
		document.getElementById("weather_4").innerHTML=weather_4;
		document.getElementById("temp_max_4").innerHTML=temp_max_4;
		document.getElementById("temp_min_4").innerHTML=temp_min_4;
		document.getElementById("pressure_4").innerHTML=pressure_4;
		document.getElementById("humidity_4").innerHTML=humidity_4;
		document.getElementById("wind_speed_4").innerHTML=wind_speed_4;

		document.getElementById("temp_5").innerHTML=temp_5;
		document.getElementById("weather_5").innerHTML=weather_5;
		document.getElementById("temp_max_5").innerHTML=temp_max_5;
		document.getElementById("temp_min_5").innerHTML=temp_min_5;
		document.getElementById("pressure_5").innerHTML=pressure_5;
		document.getElementById("humidity_5").innerHTML=humidity_5;
		document.getElementById("wind_speed_5").innerHTML=wind_speed_5;
	});
}
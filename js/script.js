if (localStorage.getItem("darkmode") == "1")
{
	darkMode();
}

started = 1;

function darkMode()
{
  
	if (document.body.style.getPropertyValue('--darkmode') == 0)
	{
		document.getElementById("darkmodeButton").innerHTML = "SAD";
		document.body.style.setProperty('--secondary-color',"var(--dark-color)");
		document.body.style.setProperty('--secondary-tint-color',"var(--dark-tint-color)");
		document.body.style.setProperty('--darkmode',"1");
		localStorage.setItem("darkmode", "1");
	}
	else
	{
		document.getElementById("darkmodeButton").innerHTML = "HAPPY";
		document.body.style.setProperty('--secondary-color',"var(--light-color)");
		document.body.style.setProperty('--secondary-tint-color',"var(--light-tint-color)");
		document.body.style.setProperty('--darkmode',"0");
		localStorage.setItem("darkmode", "0");
	}
}

document.body.addEventListener("click", function (evt)
{
	document.body.style.setProperty('--animDur',"0s");
});

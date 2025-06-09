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

window.addEventListener("load", () => 
{
	document.querySelectorAll('[class*="fade-in-"]').forEach(el =>
	{
		el.classList.add("fade-in");
		el.classList.forEach(className => 
		{
			const match = className.match(/^fade-in-(\d+(?:\.\d+)?)$/);
			if (match)
			{
				const delay = parseFloat(match[1]);
				el.style.animationDelay = `${delay}s`;
			}
		});
		el.addEventListener('animationstart', () => 
		{
			el.dataset.animationStarted = 'true';
		});
		el.addEventListener('animationend', () => 
		{
			el.dataset.animationCompleted = 'true';
			el.classList.remove("disabled");
			if (el.dataset.bsToggleOriginal != 'none')
			{
				el.setAttribute('data-bs-toggle', el.dataset.bsToggleOriginal);
			}
		});
		el.addEventListener('click', (e) =>
		{
			if (el.classList.contains('disabled'))
			{
				e.preventDefault();
			}
		});
		el.classList.add("disabled");
		if (el.hasAttribute('data-bs-toggle'))
		{
			el.dataset.bsToggleOriginal = el.getAttribute('data-bs-toggle');
			el.removeAttribute('data-bs-toggle');
		}
		else
		{
			el.dataset.bsToggleOriginal = 'none';
		}
	});

	document.querySelectorAll('[class*="float-in-"]').forEach(el =>
	{
		el.classList.add("float-in");
		el.classList.forEach(className => 
		{
			const match = className.match(/^float-in-(\d+(?:\.\d+)?)$/);
			if (match)
			{
				const delay = parseFloat(match[1]);
				el.style.animationDelay = `${delay}s`;
			}
		});
		el.addEventListener('animationstart', () => 
		{
			el.dataset.animationStarted = 'true';
		});
		el.addEventListener('animationend', () => 
		{
			el.dataset.animationCompleted = 'true';
			el.classList.remove("disabled");
			if (el.dataset.bsToggleOriginal != 'none')
			{
				el.setAttribute('data-bs-toggle', el.dataset.bsToggleOriginal);
			}
		});
		el.addEventListener('click', (e) =>
		{
			if (el.classList.contains('disabled'))
			{
				e.preventDefault();
			}
		});
		el.classList.add("disabled");
		if (el.hasAttribute('data-bs-toggle'))
		{
			el.dataset.bsToggleOriginal = el.getAttribute('data-bs-toggle');
			el.removeAttribute('data-bs-toggle');
		}
		else
		{
			el.dataset.bsToggleOriginal = 'none';
		}
	});
});

let hasClicked = false;
document.addEventListener('click', () => 
{
	if (hasClicked)
	{
		return;
	}
	hasClicked = true;

	document.querySelectorAll('[class*="fade-in-"]').forEach(el =>
	{
		if (el.dataset.animationStarted != 'true')
		{
			el.classList.forEach(className => 
			{
				const match = className.match(/^fade-in-(\d+(?:\.\d+)?)$/);
				if (match)
				{
					const originalDelay = parseFloat(match[1]);
					const newDelay = originalDelay * 0.1;

					el.style.animation = 'none';
					void el.offsetWidth;
					el.style.animation = '';

					el.style.animationDelay = `${newDelay}s`;
				}
			});
			el.classList.add("disabled");
		}
	});

	document.querySelectorAll('[class*="float-in-"]').forEach(el =>
	{
		if (el.dataset.animationStarted != 'true')
		{
			el.classList.forEach(className => 
			{
				const match = className.match(/^float-in-(\d+(?:\.\d+)?)$/);
				if (match)
				{
					const originalDelay = parseFloat(match[1]);
					const newDelay = originalDelay * 0.1;

					el.style.animation = 'none';
					void el.offsetWidth;
					el.style.animation = '';

					el.style.animationDelay = `${newDelay}s`;
				}
			});
			el.classList.add("disabled");
		}		
	});
});
const defcolor1 = document.body.style.getPropertyValue('--butt-sec-text');
const defcolor2 = document.body.style.getPropertyValue('--navbar-bg');
const defcolor3 = document.body.style.getPropertyValue('--card-bg');
const defcolor4 = document.body.style.getPropertyValue('--def-main-text');
const defcolor6 = document.body.style.getPropertyValue('--bg');
const defcolor7 = document.body.style.getPropertyValue('--bgGrad');
const defcolor8 = document.body.style.getPropertyValue('--input-name-bg');
const defcolor9 = document.body.style.getPropertyValue('--input-border');
var formNum = 0;
var started = 0;

if (localStorage.getItem("darkmode") == "1")
{
  darkMode();
}

started = 1;

function darkMode()
{
  
  if (document.body.style.getPropertyValue('--darkmode') == 0)
  {
    if (started == 1) document.body.style.animation = "bgSwitchL2D 1s linear 0s";
    document.getElementById("darkmodeButton").innerHTML = "HAPPY";
    document.body.style.setProperty('--butt-sec-text',"rgba(15, 15, 15, 1)");
    document.body.style.setProperty('--navbar-bg',"rgba(0, 0, 0, 0.95)");
    document.body.style.setProperty('--card-bg',"rgba(15, 15, 15, 1)");
    document.body.style.setProperty('--def-main-text',"white");
    document.body.style.setProperty('--bg',"rgb(10, 10, 10)");
    document.body.style.setProperty('--bgGrad',"rgba(5, 5, 5, 0.5)");
    document.body.style.setProperty('--input-name-bg',"rgba(25, 25, 25, 1)");
    document.body.style.setProperty('--input-border',"rgba(50, 50, 50, 1)");
    document.body.style.setProperty('--darkmode',"1");
    localStorage.setItem("darkmode", "1");
  }
  else
  {
    if (started == 1) document.body.style.animation = "bgSwitchD2L 1s linear 0s";
    document.getElementById("darkmodeButton").innerHTML = "SAD";
    document.body.style.setProperty('--butt-sec-text',defcolor1);
    document.body.style.setProperty('--navbar-bg',defcolor2);
    document.body.style.setProperty('--card-bg',defcolor3);
    document.body.style.setProperty('--def-main-text',defcolor4);
    document.body.style.setProperty('--bg',defcolor6);
    document.body.style.setProperty('--bgGrad',defcolor7);
    document.body.style.setProperty('--input-name-bg',defcolor8);
    document.body.style.setProperty('--input-border',defcolor9);
    document.body.style.setProperty('--darkmode',"0");
    localStorage.setItem("darkmode", "0");
  }
}

function nextForm()
{
  formNum++;
  const formBods = document.getElementsByName("formBody");
  const formHeads = document.getElementsByName("formHead");
  formBods[formNum - 1].classList.toggle("d-none");
  formBods[formNum].classList.toggle("d-none");
  formHeads[formNum - 1].classList.toggle("active");
  formHeads[formNum].classList.toggle("active");
}

function prevForm()
{
  formNum--;
  const formBods = document.getElementsByName("formBody");
  const formHeads = document.getElementsByName("formHead");
  formBods[formNum + 1].classList.toggle("d-none");
  formBods[formNum].classList.toggle("d-none");
  formHeads[formNum + 1].classList.toggle("active");
  formHeads[formNum].classList.toggle("active");
}

function setForm(param)
{
  const formBods = document.getElementsByName("formBody");
  const formHeads = document.getElementsByName("formHead");
  formBods[formNum].classList.toggle("d-none");
  formBods[param].classList.toggle("d-none");
  formHeads[formNum].classList.toggle("active");
  formHeads[param].classList.toggle("active");
  formNum = param;
}

document.body.addEventListener("click", function (evt)
{
  document.body.style.setProperty('--animDur',".1s");
});

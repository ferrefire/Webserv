var country = 0;
var state = 0;
var city = 0;

fetch("../json/countries2.json")
  .then((response) => response.json())
  .then((json) => setSelects(json));

function setSelects(testDB)
{
    let textC = "<option selected>Click to select a country</option>";
    for (let i in testDB)
    {
      textC += "<option value=" + i + ">" + testDB[i].name + "</option>";
    }
    document.getElementById("countrySelect").innerHTML = textC;

    document.getElementById("countrySelect").addEventListener("change",
    function handleChange(event)
    {
        let index = event.target.value;
        country = index;
        let textR = "<option selected>Click to select a region</option>";
        for (let j in testDB[index].states)
        {
          textR += "<option value=" + j + ">" + testDB[index].states[j].name + "</option>";
        }
        document.getElementById("regionSelect").innerHTML = textR;
        document.getElementById("countryNum").innerHTML = "+" + testDB[index].phone_code;
        //console.log(event.target.value);
        //console.log(testDB[event.target.value].name);
    });
    document.getElementById("regionSelect").addEventListener("change",
    function handleChange(event)
    {
        let index = event.target.value;
        state = index;
        let textCi = "<option selected>Click to select a city</option>";
        for (let k in testDB[country].states[index].cities)
        {
          textCi += "<option value=" + k + ">" + testDB[country].states[index].
          cities[k].name + "</option>";
        }
        document.getElementById("citySelect").innerHTML = textCi;
        //console.log(event.target.value);
        //console.log(testDB[event.target.value].name);
    });
}

const dateInputs = document.getElementsByTagName("input");
const patt = document.createAttribute("pattern");
patt.value = "\d\d//\d\d//\d\d\d\d";
for (let i in dateInputs.length)
{
  if (dateInputs.elements[i].getAttribute("type") == "date")
  {
    dateInputs.elements[i].setAttributeNode(patt);
  }
}

/*const numInputs = document.getElementsByName("numInput");
for (let i in numInputs)
{
  setInputFilter(numInputs[i], function(value) 
  {
    return /^-?\d*$/.test(value); // Allow digits and '.' only, using a RegExp.
  }, "Only digits are allowed");
}

function setInputFilter(textbox, inputFilter, errMsg) 
{
  [ "input", "keydown", "keyup", "mousedown", "mouseup", "select", "contextmenu", "drop", "focusout" ].forEach(function(event) {
    textbox.addEventListener(event, function(e) 
    {
      if (inputFilter(this.value)) {
        // Accepted value.
        if ([ "keydown", "mousedown", "focusout" ].indexOf(e.type) >= 0)
        {
          this.classList.remove("input-error");
          this.setCustomValidity("");
        }

        this.oldValue = this.value;
        this.oldSelectionStart = this.selectionStart;
        this.oldSelectionEnd = this.selectionEnd;
      }
      else if (this.hasOwnProperty("oldValue")) 
      {
        // Rejected value: restore the previous one.
        this.classList.add("input-error");
        this.setCustomValidity(errMsg);
        this.reportValidity();
        this.value = this.oldValue;
        this.setSelectionRange(this.oldSelectionStart, this.oldSelectionEnd);
      }
      else 
      {
        // Rejected value: nothing to restore.
        this.value = "";
      }
    });
  });
}*/

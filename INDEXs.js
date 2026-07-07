// ── String Methods ──
function greetUser() {
  var name = document.getElementById("nameInput").value;

  if (name.trim() === "") {
    alert("Please enter your name!");
    return;
  }

  var upper     = name.toUpperCase();
  var lower     = name.toLowerCase();
  var length    = name.length;
  var trimmed   = name.trim();

  var msg = "Hello, " + upper + "! Welcome!";
  msg += "\nLowercase: " + lower;
  msg += "\nName length: " + length;
  msg += "\nTrimmed: " + trimmed;

  document.getElementById("message").innerText = msg;
}


function showConfirm() {
  var result = confirm("Do you want to reset the message?");
  if (result) {
    document.getElementById("message").innerText = "Message cleared.";
  }
}

function showPrompt() {
  var city = prompt("Which city are you from?");
  if (city !== null) {
    document.getElementById("message").innerText = "You are from: " + city;
  }
}
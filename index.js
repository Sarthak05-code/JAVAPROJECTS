function calculateTotalAndAverage(marksArray) {
  var total = 0;
  for (var i = 0; i < marksArray.length; ++i) {
    total += marksArray[i];
  }
  var average = total / marksArray.length;
  return { total: total, average: average };
}

function getGrade(average) {
  var grade;

  if (average >= 90) grade = "A+";
  else if (average >= 80) grade = "A";
  else if (average >= 70) grade = "B+";
  else if (average >= 60) grade = "B";
  else if (average >= 50) grade = "C+";
  else if (average >= 40) grade = "C";
  else grade = "NG";
  return grade;
}

function calculateResult() {
  var name = document.getElementById("studentName").value;

  var m1 = Number(document.getElementById("m1").value);
  var m2 = Number(document.getElementById("m2").value);
  var m3 = Number(document.getElementById("m3").value);
  var m4 = Number(document.getElementById("m4").value);
  var m5 = Number(document.getElementById("m5").value);
  var marks = [m1, m2, m3, m4, m5];

  var result = calculateTotalAndAverage(marks);

  var total = result.total;
  var average = result.average;
  var grade = getGrade(average);

  var output =
    "Name: " +
    name +
    "<br>" +
    "Total: " +
    total +
    "<br>" +
    "Average: " +
    average +
    "<br>" +
    "Grade: " +
    grade +
    "<br>";

    document.getElementById("resultOutput").innerHTML = output;
}
function revalidateMarks () {
    var ids = ["m1" , "m2" , "m3" , "m4" , "m5"]
    for(var i = 0 ; i < ids.length ; ++i) {
        var field = document.getElementById(ids[i])
        var value = Number(field.value)
        if(value < 0 || value > 100 || isNaN(value)) {
            alert("Enter a valid marks , betwee 0  and 100")
            field.value = "";
        }
    }
}

function highlightResult() {
    document.getElementById("resultSection").style.backgroundColor = "yellow"
}

function unhighlightResult() {
    document.getElementById("resultSection").style.backgroundColor = "";
}
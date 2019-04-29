
$(document).ready(function () {
        $('#1').click(function() {
//      console.log("pressed");
            js2php("1");
        });
        $('#2').click(function() {
          js2php("2");
//            console.log("mouse up");
        });
      $('#3').click(function() {
          js2php("3");
//            console.log("mouse up");
        });
      $('#4').click(function() {
          js2php("4");
//            console.log("mouse up");
        });
      $('#5').click(function() {
          js2php("0");
//            console.log("mouse up");
        });
});

function js2php(qData) {
    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open("GET", "main.php?q=" + qData, true);
    xmlhttp.send();
    console.log(qData);
}

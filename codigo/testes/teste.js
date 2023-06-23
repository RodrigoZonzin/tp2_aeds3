const util = require('util');

function randInt(min, max) { // min and max included 
    return Math.floor(Math.random() * (max - min + 1) + min)
}


var  T = randInt(3, 7); 
T = 1; 


console.log(T);
for(var i = 0; i<T; i++){
    //var R = randInt(30, 50),
    //    C = randInt(30,50);
    var R = 1000, C = 1000;
    console.log(R+" "+C);
    for (var j = 0; j < R; j++) {
        var line = "";
        for (var k = 0; k < C; k++) {
            var num = randInt(-30, 20);
            line += num + " ";
        }
        console.log(line.trim());
    }
}
ws = new WebSocket("ws://localhost:8000/");
ws.onopen = function(e) {
    //ws.send(1);
};
function read() {
    ws.onmessage = function(e){        
        console.log(e.data)
    };
}

function sleep() {
    setTimeout("read()", 1000);
}

read();
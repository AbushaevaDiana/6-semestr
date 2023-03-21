function generatePalette(palette, context) {
    for (var r = 0, max = 3; r <= max; r++) {
      for (var g = 0; g <= max; g++) {
        for (var b = 0; b <= max; b++) {
          var paletteBlock = document.createElement('div');
          paletteBlock.className = 'button';
          paletteBlock.addEventListener('click', function changeColor(e) {
            context.strokeStyle = e.target.style.backgroundColor;
          });

          paletteBlock.style.backgroundColor = (
            'rgb(' + Math.round(r * 255/ max) + ", "
            + Math.round(g * 255/max) + ", "
            + Math.round(b * 255/max) + ")"
          );

          palette.appendChild(paletteBlock);
        }
      }
    }
}

function loadFile(canvas)
{
    const context = canvas.getContext('2d');
    const loadfile = document.getElementById("loadfile");
    loadfile.addEventListener('change', function(e) {
        context.clearRect(0,0, canvas.width, canvas.height);
        var URL = window.webkitURL || window.URL;
        var url = URL.createObjectURL(e.target.files[0]);
        var img = new Image();
        img.src = url;
        img.onload = function(){
            context.drawImage(img, 0, 0, 500, 500);
        }
        document.getElementById('save').hidden = false;
    });  
}

function newCanvas()
{
    const canvas = document.getElementById('canvas');    
    const context = canvas.getContext('2d');
    document.getElementById('save').hidden = false;
    context.clearRect(0,0, canvas.width, canvas.height); 

    context.rect(0, 0, 500, 500);
    context.fillStyle = 'white';
    context.fill();   
}

function draw(){
    const canvas = document.getElementById('canvas');    
    const context = canvas.getContext('2d');
    generatePalette(document.getElementById("palette"), context);

    
    context.lineCap = "round";
    var kist = canvas.height/100*5;
    context.lineWidth = kist;
 
    canvas.onmousemove = function drawIfPressed(e){
      var x = e.offsetX;
      var y = e.offsetY;
      var dx = e.movementX;
      var dy = e.movementY;
 
      if (e.buttons == 1) {
        context.beginPath();
        context.moveTo(x, y);
        context.lineTo(x - dx, y - dy);
        context.stroke();
        context.closePath();
      }

    };
 
    loadFile(canvas);
}

function getImage(canvas){
    var imageData = canvas.toDataURL();
    var image = new Image();
    image.src = imageData;
    return image;
}
 
function saveImage(image) {
    var link = document.createElement("a");
 
    link.setAttribute("href", image.src);
    link.setAttribute("download", "canvasImage");
    link.click();
}
 
window.onload = () => draw();
 
function saveCanvasAsImageFile(){
    var image = getImage(document.getElementById("canvas"));
    saveImage(image);
}
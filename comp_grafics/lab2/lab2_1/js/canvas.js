function loadFile(canvas)
{
    const context = canvas.getContext('2d');
    const loadfile = document.getElementById("loadfile");

    var img_f = new Image();
    img_f.src = "img/fon.jpg";

    loadfile.addEventListener('change', function(e) {
        var URL = window.webkitURL || window.URL;
        var url = URL.createObjectURL(e.target.files[0]);
        var img = new Image();
        img.src = url;

        context.clearRect(0,0, canvas.width, canvas.height);
        context.drawImage(img_f, 0, 0, canvas.width, canvas.height);
         
        img.onload = function(){
          var cof = 1;

          if(this.width > canvas.width)
          {
            cof = canvas.width/this.width
          }
          if(this.height*cof > canvas.height)
          {
            cof = canvas.height/this.height
          }
            context.drawImage(img, 0, 0, this.width*cof, this.height*cof);
        }

    });  
}

function draw(){
    const canvas = document.getElementById('canvas'); 
 
    loadFile(canvas);
}
 
window.onload = () => draw();


///фон повторяющийся, а не подстраивающийся, размножить картинку
//подстраивать область под размер картинки
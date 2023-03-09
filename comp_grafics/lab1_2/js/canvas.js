function draw(){
    const canvas = document.getElementById('canvas');    
    const context = canvas.getContext('2d');

//Капюшон
    context.beginPath();
    context.arc(150, 150, 100, 0, Math.PI * 2);
    context.fillStyle = '#FF4500';
    context.fill();

//Отвороты капюшона
    context.beginPath();
    context.ellipse(150, 157, 74, 64, 0 , Math.PI*2, 0);
    context.strokeStyle = '#000000'; 
    context.lineWidth = 1;
    context.stroke();

    context.beginPath();
    context.moveTo(152, 93);
    context.bezierCurveTo(235, 95, 235, 220, 152, 210);
    context.fillStyle = '#A0522D';
    context.fill();

    context.beginPath();
    context.moveTo(152, 93);
    context.bezierCurveTo(45, 90, 75, 225, 152, 210);
    context.fillStyle = '#A0522D';
    context.fill();

//Лицо
    context.beginPath();
    context.ellipse(110, 150, 80, 65, 0 , -Math.PI/3, Math.PI/3);
    context.strokeStyle = '#FFFACD';
    context.fillStyle = '#FFFACD';
    context.fill();
    context.stroke(); 
    
    context.beginPath();
    context.ellipse(200, 150, 95, 65, 0 , (Math.PI/3)*2, (-Math.PI/3)*2);
    context.strokeStyle = '#FFFACD';
    context.fillStyle = '#FFFACD';
    context.fill();
    context.stroke();

//Глаза
    context.beginPath();
    context.ellipse(175, 148, 25, 30, -Math.PI/6, Math.PI*2, 0);
    context.fillStyle = '#FFFFFF';
    context.fill();

    context.beginPath();
    context.ellipse(125, 145, 25, 30, Math.PI/6 , Math.PI*2, 0);
    context.fillStyle = '#FFFFFF';
    context.fill();

    context.beginPath();
    context.ellipse(125, 145, 25, 30, Math.PI/6 , -5*(Math.PI/6), -(Math.PI/4));
    context.strokeStyle = '#DEB887';
    context.stroke();

    context.beginPath();
    context.ellipse(175, 148, 25, 30, -Math.PI/6 , -5*(Math.PI/6), -(Math.PI/5));
    context.strokeStyle = '#DEB887';
    context.stroke();

    context.beginPath();
    context.arc(130, 145, 4, 0, Math.PI * 2);
    context.fillStyle = '#000000';
    context.fill();

    context.beginPath();
    context.arc(168, 148, 4, 0, Math.PI * 2);
    context.fillStyle = '#000000';
    context.fill();

//Куртка
    context.fillStyle = '#FF4500';
    context.fillRect(90, 230, 120, 85);

    context.fillStyle = '#FF4500';
    context.fillRect(80, 240, 140, 55);

//Обувь
    context.beginPath();
    context.moveTo(85, 315);
    context.lineTo(215, 315);
    context.lineCap = 'round';
    context.lineWidth = 5;
    context.strokeStyle = '#000000';
    context.stroke();

//Рукава
    context.beginPath();
    context.ellipse(85, 255, 10, 35, Math.PI/10 , Math.PI*2, 0);
    context.strokeStyle = '#FF4500';
    context.fillStyle = '#FF4500';
    context.fill();
    context.stroke();

    context.beginPath();
    context.ellipse(215, 255, 10, 35, -Math.PI/10 , Math.PI*2, 0);
    context.strokeStyle = '#FF4500';
    context.fillStyle = '#FF4500';
    context.fill();
    context.stroke();

    context.beginPath();
    context.moveTo(95, 253);
    context.lineWidth = 1;
    context.quadraticCurveTo(89, 265, 89, 275);
    context.strokeStyle = '#000000';
    context.stroke();

    context.beginPath();
    context.moveTo(205, 253);
    context.lineWidth = 1;
    context.quadraticCurveTo(211, 265, 210, 275);
    context.strokeStyle = '#000000';
    context.stroke();

//Перчатки
    context.beginPath();
    context.ellipse(225, 275, 15, 17, -Math.PI/6, Math.PI*2, 0);
    context.fillStyle = '#A0522D';
    context.fill();

    context.beginPath();
    context.ellipse(75, 275, 15, 17, Math.PI/6, Math.PI*2, 0);
    context.fillStyle = '#A0522D';
    context.fill();

    context.beginPath();
    context.arc(210, 270, 6, 0, Math.PI * 2);
    context.lineWidth = 1;
    context.strokeStyle = '#8B4513';
    context.fillStyle = '#A0522D';
    context.fill();
    context.stroke();

    context.beginPath();
    context.arc(90, 270, 6, 0, Math.PI * 2);
    context.lineWidth = 1;
    context.strokeStyle = '#8B4513';
    context.fillStyle = '#A0522D';
    context.fill();
    context.stroke();

//Тень от капюшона
    context.beginPath();
    context.arc(150, 150, 100, 0, Math.PI * 2);
    context.strokeStyle = '#FF0000';
    context.stroke();

//Завязки
    context.beginPath();
    context.arc(150, 207, 1, 0, Math.PI * 2);
    context.fillStyle = '#000000';
    context.fill();

    context.beginPath();
    context.moveTo(150, 207);
    context.strokeStyle = '#000000';
    context.lineWidth = 1;
    context.lineTo(140, 238);
    context.stroke();

    context.beginPath();
    context.moveTo(150, 207);
    context.bezierCurveTo(155, 210, 145, 235, 157, 245);
    context.stokeStyle = '#000000';
    context.stroke();

//Застежка
    context.beginPath();
    context.moveTo(150, 250);
    context.lineTo(150, 300);
    context.lineWidth = 2;
    context.strokeStyle = '#8B4513';
    context.stroke();
}

window.onload = () => draw();
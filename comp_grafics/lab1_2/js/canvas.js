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

    //Второй
    //
    //

//Куртка
    context.fillStyle = '#4169E1';
    context.fillRect(390, 230, 120, 85);

    context.fillStyle = '#CD5C5C';
    context.fillRect(380, 240, 140, 60);

//Обувь

    context.beginPath();
    context.moveTo(380, 315);
    context.lineWidth = 1;
    context.quadraticCurveTo(415, 305, 450, 315);
    context.fillStyle = '#000000';
    context.fill();

    context.beginPath();
    context.moveTo(450, 315);
    context.lineWidth = 1;
    context.quadraticCurveTo(475, 305, 520, 315);
    context.fillStyle = '#000000';
    context.fill();

//Рукава
    context.beginPath();
    context.ellipse(385, 255, 10, 35, Math.PI/10 , Math.PI*2, 0);
    context.fillStyle = '#CD5C5C';
    context.fill();

    context.beginPath();
    context.ellipse(515, 255, 10, 35, -Math.PI/10 , Math.PI*2, 0);
    context.fillStyle = '#CD5C5C';
    context.fill();

    context.beginPath();
    context.moveTo(395, 253);
    context.lineWidth = 1;
    context.quadraticCurveTo(389, 265, 389, 275);
    context.strokeStyle = '#000000';
    context.stroke();

    context.beginPath();
    context.moveTo(505, 253);
    context.lineWidth = 1;
    context.quadraticCurveTo(511, 265, 510, 275);
    context.strokeStyle = '#000000';
    context.stroke();

//Застежка
    context.beginPath();
    context.moveTo(450, 250);
    context.lineTo(445, 300);
    context.lineCap='butt';
    context.lineWidth = 3;
    context.strokeStyle = '#2F4F4F';
    context.stroke();

    context.beginPath();
    context.arc(440, 265, 2, 0, Math.PI * 2);
    context.fillStyle = '#2F4F4F';
    context.fill();

    context.beginPath();
    context.arc(438, 280, 2, 0, Math.PI * 2);
    context.fillStyle = '#2F4F4F';
    context.fill();

    context.beginPath();
    context.arc(436, 295, 2, 0, Math.PI * 2);
    context.fillStyle = '#2F4F4F';
    context.fill();

//Воротник
    context.beginPath();
    context.ellipse(420, 242, 11, 33, -7*Math.PI/3, Math.PI*2, 0);
    context.strokeStyle = '#B22222';
    context.stroke();
    context.fillStyle = '#FF0000';
    context.fill();

    context.beginPath();
    context.ellipse(480, 247, 11, 33, 4*Math.PI/11, Math.PI*2, 0);
    context.strokeStyle = '#B22222';
    context.stroke();
    context.fillStyle = '#FF0000';
    context.fill();

//Голова
    context.beginPath();
    context.arc(450, 150, 97, 0, Math.PI * 2);
    context.fillStyle = '#FFFACD';
    context.fill();

//Шапка
    context.beginPath();
    context.arc(450, 150, 100, -7*Math.PI/8, -Math.PI/8);
    context.strokeStyle = '#4169E1';
    context.fillStyle = '#4169E1';
    context.stroke();
    context.fill();

    context.beginPath();
    context.moveTo(350, 120);
    context.lineCap='butt';
    context.lineWidth = 20;
    context.quadraticCurveTo(455, 85, 550, 120);
    context.strokeStyle = '#FF0000';
    context.stroke();

//Помпон
    context.lineCap = 'round';
    context.lineWidth = 5;
    context.strokeStyle = '#FF0000';

    context.beginPath();
    context.moveTo(430, 35);
    context.lineTo(432, 67);
    context.stroke();

    context.beginPath();
    context.moveTo(423, 40);
    context.lineTo(440, 67);
    context.stroke();

    context.beginPath();
    context.moveTo(417, 45);
    context.lineTo(447, 62);
    context.stroke();

    context.beginPath();
    context.moveTo(415, 53);
    context.lineTo(447, 52);
    context.stroke();

    context.beginPath();
    context.moveTo(417, 60);
    context.lineTo(447, 45);
    context.stroke();

    context.beginPath();
    context.moveTo(438, 38);
    context.lineTo(425, 67);
    context.stroke();

//Глаза
    context.beginPath();
    context.ellipse(475, 148, 25, 30, -Math.PI/6, Math.PI*2, 0);
    context.fillStyle = '#FFFFFF';
    context.fill();

    context.beginPath();
    context.ellipse(425, 145, 25, 30, Math.PI/6 , Math.PI*2, 0);
    context.fillStyle = '#FFFFFF';
    context.fill();

    context.beginPath();
    context.ellipse(425, 145, 25, 30, Math.PI/6 , -5*(Math.PI/6), -(Math.PI/4));
    context.lineWidth = 1/2;
    context.strokeStyle = '#DEB887';
    context.stroke();

    context.beginPath();
    context.ellipse(475, 148, 25, 30, -Math.PI/6 , -5*(Math.PI/6), -(Math.PI/5));
    context.strokeStyle = '#DEB887';
    context.stroke();

    context.beginPath();
    context.arc(430, 145, 4, 0, Math.PI * 2);
    context.fillStyle = '#000000';
    context.fill();

    context.beginPath();
    context.arc(468, 148, 4, 0, Math.PI * 2);
    context.fillStyle = '#000000';
    context.fill();

//Брови
    context.lineCap = 'butt';
    context.lineWidth = 3;
    context.strokeStyle = '#000000';

    context.beginPath();
    context.moveTo(380, 125);
    context.lineTo(400, 107);
    context.stroke();

    context.beginPath();
    context.moveTo(510, 125);
    context.lineTo(490, 107);
    context.stroke();

//Рот
    context.beginPath();
    context.moveTo(450, 235);
    context.lineTo(425, 215);
    context.lineTo(475, 215);
    context.lineTo(450, 235);
    context.lineCap='round';
    context.lineWidth = 3;
    context.fillStyle = '#FFFFFF';
    context.strokeStyle = '#000000';
    context.stroke();
    context.fill();

    context.beginPath();
    context.moveTo(450, 235);
    context.lineTo(433, 222);
    context.lineTo(467, 222);
    context.lineCap='round';
    context.lineWidth = 3;
    context.fillStyle = '#000000';
    context.fill();

    context.lineCap='round';
    context.lineWidth = 2;
    context.strokeStyle = '#000000';

    context.beginPath();
    context.moveTo(450, 215);
    context.lineTo(451, 225);
    context.stroke();

    context.beginPath();
    context.moveTo(441, 215);
    context.lineTo(439, 225);
    context.stroke();

    context.beginPath();
    context.moveTo(463, 215);
    context.lineTo(460, 225);
    context.stroke();

//Перчатки
    context.beginPath();
    context.ellipse(525, 275, 15, 17, -Math.PI/6, Math.PI*2, 0);
    context.fillStyle = '#FF0000';
    context.fill();

    context.beginPath();
    context.ellipse(375, 275, 15, 17, Math.PI/6, Math.PI*2, 0);
    context.fillStyle = '#FF0000';
    context.fill();

    context.beginPath();
    context.arc(510, 270, 6, 0, Math.PI * 2);
    context.lineWidth = 1;
    context.strokeStyle = '#B22222';
    context.fillStyle = '#FF0000';
    context.fill();
    context.stroke();

    context.beginPath();
    context.arc(390, 270, 6, 0, Math.PI * 2);
    context.lineWidth = 1;
    context.strokeStyle = '#B22222';
    context.fillStyle = '#FF0000';
    context.fill();
    context.stroke();
}

window.onload = () => draw();
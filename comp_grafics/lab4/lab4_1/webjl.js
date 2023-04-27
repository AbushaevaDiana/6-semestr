import * as THREE from './libs/three.module.js';
import { OrbitControls } from './src/OrbitControls.js';
import { TorusGeometry } from './src/Torus.js';

const WIDTH = window.innerWidth;
const HEIGHT = window.innerHeight;


window.onload = () => {

    const canvas = document.getElementById('canvas');
    canvas.width = WIDTH;
    canvas.height = HEIGHT;

    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera( 100, WIDTH / HEIGHT, 0.1, 1000 );
    camera.position.set(0, 30, 15);

    const renderer = new THREE.WebGLRenderer({ canvas });
    renderer.setSize( WIDTH, HEIGHT );
    scene.background = new THREE.Color(0xffffff);

    const controls = new OrbitControls(camera, renderer.domElement);
    controls.enableDamping = false;//инерция
    controls.minDistance = 10;
    controls.maxDistance = 30;

    const geometry = new TorusGeometry();
    const material = new THREE.MeshBasicMaterial({
        color: 0x000555,
        wireframe: true,//сегметы
    });

    
    const torus = new THREE.Mesh(geometry, material);
    scene.add(torus);

    const animate = () => {
        requestAnimationFrame(animate);
        controls.update();
        renderer.render(scene, camera);
    }

    animate();
}
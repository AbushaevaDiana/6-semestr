import { BufferGeometry } from '../libs/three.module.js';
import { Float32BufferAttribute } from '../libs/three.module.js';
import { Vector3 } from '../libs/three.module.js';

class TorusGeometry extends BufferGeometry {

	constructor() {

        const radius = 10; 
        const tube = 3; 
        let radialSegments = 10; 
        let tubularSegments = 20; 
        const arc = Math.PI * 2;

		super();

		const indices = [];
		const vertices = [];
		const vertex = new Vector3();

		for ( let j = 0; j <= radialSegments; j ++ ) {

			for ( let i = 0; i <= tubularSegments; i ++ ) {

				const alfa = i / tubularSegments * arc;
				const beta = j / radialSegments * Math.PI * 2;

				// vertex
				vertex.x = ( radius + tube * Math.cos( beta ) ) * Math.cos( alfa );
				vertex.y = ( radius + tube * Math.cos( beta ) ) * Math.sin( alfa );
				vertex.z = tube * Math.sin( beta );

				vertices.push( vertex.x, vertex.y, vertex.z );


                if(i >= 1 && j >= 1)//без ограничения тянутся лучи к середине
                {
                    // indices

				    const a = ( tubularSegments + 1 ) * j + i - 1;
				    const b = ( tubularSegments + 1 ) * ( j - 1 ) + i - 1;
				    const c = ( tubularSegments + 1 ) * ( j - 1 ) + i;
				    const d = ( tubularSegments + 1 ) * j + i;

				    // faces
				    indices.push( a, b, d );
				    indices.push( b, c, d );
                }

			}

		}

		// build geometry
        console.log(indices);

		this.setIndex( indices );
		this.setAttribute( 'position', new Float32BufferAttribute( vertices, 3 ) );
	}

	copy( source ) {
		super.copy( source );
		this.parameters = Object.assign( {}, source.parameters );
		return this;
	}

}

export { TorusGeometry };
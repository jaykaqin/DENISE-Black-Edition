/*------------------------------------------------------------------------
 * Module for storage of Preconditioned Conjugate Gradient Method (PCG)
 * for the material parameters vp, vs, rho and lambda, mu, rho respectively
 * 
 * Daniel Koehn
 * Kiel, 12.08.2016
 * ----------------------------------------------------------------------*/

#include "fd.h"

void store_PCG_PSV(float * PCG_old, float ** waveconv, float ** waveconv_u, float ** waveconv_rho){

	extern int NX, NY, IDX, IDY;
	int i, j, h;
	
	/* ============================================================================================================================================================== */
	/* ===================================================== GRADIENT VP/ZP/lambda ================================================================================== */
	/* ============================================================================================================================================================== */

        h=1;
	/* store gradient */
	for (i=1;i<=NX;i=i+IDX){
	   for (j=1;j<=NY;j=j+IDY){

		 PCG_old[h] = waveconv[j][i];

                 h++;
	   }
	}

	/* ============================================================================================================================================================== */
	/* ===================================================== GRADIENT VS/ZS/mu ====================================================================================== */
	/* ============================================================================================================================================================== */
	

	/* store gradient */
	for (i=1;i<=NX;i=i+IDX){
	   for (j=1;j<=NY;j=j+IDY){

		 PCG_old[h] = waveconv_u[j][i];

                 h++;
	   }
	}

	/* ============================================================================================================================================================== */
	/* ===================================================== GRADIENT rho =========================================================================================== */
	/* ============================================================================================================================================================== */

	/* store gradient */
	for (i=1;i<=NX;i=i+IDX){
	   for (j=1;j<=NY;j=j+IDY){

		 PCG_old[h] = waveconv_rho[j][i];

                 h++;
	   }
	}


}

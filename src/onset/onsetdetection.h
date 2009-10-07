/*
	 Copyright (C) 2003 Paul Brossier

	 This program is free software; you can redistribute it and/or modify
	 it under the terms of the GNU General Public License as published by
	 the Free Software Foundation; either version 2 of the License, or
	 (at your option) any later version.

	 This program is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 GNU General Public License for more details.

	 You should have received a copy of the GNU General Public License
	 along with this program; if not, write to the Free Software
	 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
	 
*/

/** \file
 
  Onset detection functions
 
  All of the following onset detection function take as arguments the FFT of a
  windowed signal (as created with aubio_pvoc). They output one smpl_t per
  buffer and per channel (stored in a vector of size [channels]x[1]).
 
  These functions were first adapted from Juan Pablo Bello's code, and now
  include further improvements and modifications made within aubio.

*/


#ifndef ONSETDETECTION_H
#define ONSETDETECTION_H

#ifdef __cplusplus
extern "C" {
#endif

/** onsetdetection types */
typedef enum {
        aubio_onset_energy,         /**< energy based */          
        aubio_onset_specdiff,       /**< spectral diff */         
        aubio_onset_hfc,            /**< high frequency content */
        aubio_onset_complex,        /**< complex domain */        
        aubio_onset_phase,          /**< phase fast */            
        aubio_onset_kl,             /**< Kullback Liebler */
        aubio_onset_mkl,            /**< modified Kullback Liebler */
        aubio_onset_specflux,       /**< spectral flux */
} aubio_onsetdetection_type;

/** onsetdetection structure */
typedef struct _aubio_onsetdetection_t aubio_onsetdetection_t;
/** execute onset detection function on a spectral frame 

  Generic function to compute onset detection.
 
  \param o onset detection object as returned by new_aubio_onsetdetection()
  \param fftgrain input signal spectrum as computed by aubio_pvoc_do
  \param onset output vector (one sample long, to send to the peak picking)

*/
void aubio_onsetdetection_do (aubio_onsetdetection_t *o, cvec_t * fftgrain, fvec_t * onset);
/** creation of an onset detection object 

  \param type onset detection mode
  \param size length of the input spectrum frame
  \param channels number of input channels

*/
aubio_onsetdetection_t * new_aubio_onsetdetection(aubio_onsetdetection_type type, uint_t size, uint_t channels);
/** deletion of an onset detection object

  \param o onset detection object as returned by new_aubio_onsetdetection()

*/
void del_aubio_onsetdetection(aubio_onsetdetection_t *o);

#ifdef __cplusplus
}
#endif

#endif /* ONSETDETECTION_H */

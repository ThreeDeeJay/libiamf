/*
BSD 3-Clause Clear License The Clear BSD License

Copyright (c) 2023, Alliance for Open Media.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * @file opus_multistream2_decode.h
 * @brief opus decoder APIs.
 * @version 0.1
 * @date Created 03/03/2023
 **/

#ifndef _OPUS_MULTISTREAM2_DECODER_H_
#define _OPUS_MULTISTREAM2_DECODER_H_

#include <stdint.h>

typedef struct OpusMS2Decoder OpusMS2Decoder;

/**
 * @brief     Create an opus decoder.
 * @param     [in] Fs : the sample rate.
 * @param     [in] streams : the audio stream count.
 * @param     [in] coupled_streams : the coupled audio stream count.
 * @param     [in] flags : pcm storage order.
 * @param     [in] error : the error code when open an aac decoder.
 * @return    return an opus decoder handle.
 */
OpusMS2Decoder *opus_multistream2_decoder_create(int Fs, int streams,
                                                 int coupled_streams,
                                                 uint32_t flags, int *error);

/**
 * @brief     Decode opus packet.
 * @param     [in] st : opus decoder handle.
 * @param     [in] buffer : the flac packet buffer.
 * @param     [in] len : the length of flac packet buffer.
 * @param     [in] pcm : the decoded pcm frame.
 * @param     [in] frame_size : the frame size of aac.
 * @return    return the number of decoded samples.
 */
int opus_multistream2_decode(OpusMS2Decoder *st, uint8_t *buffer[],
                             uint32_t len[], void *pcm, uint32_t frame_size);

/**
 * @brief     Destory an opus decoder.
 * @param     [in] st : opus decoder handle.
 */
void opus_multistream2_decoder_destroy(OpusMS2Decoder *st);

#endif /* _OPUS_MULTISTREAM2_DECODER_H_ */

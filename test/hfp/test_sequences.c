/*
 * Copyright (C) 2014 BlueKitchen GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 4. Any redistribution, use, or modification is done solely for
 *    personal benefit and not for any commercial purpose or for
 *    monetary gain.
 *
 * THIS SOFTWARE IS PROVIDED BY BLUEKITCHEN GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTHIAS
 * RINGWALD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Please inquire about commercial licensing options at 
 * contact@bluekitchen-gmbh.com
 *
 */
 
// *****************************************************************************
//
// HFP Test Sequences
//
// *****************************************************************************

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_sequences.h"


#define TEST_SEQUENCE(test_sequence) { (char *)#test_sequence, (char**)test_sequence, sizeof(test_sequence) / sizeof(char *)}

/* Service Level Connection (slc) common commands */
const char * slc_cmds_test1[] = {
    "AT+BAC=1,3", 
    "OK"
};

hfp_test_item_t slc_cmds_tests[] = {
    TEST_SEQUENCE(slc_cmds_test1)
};

/* Codecs Connection (cc) test sequences */
const char * cc_test1[] = {
    "AT+BCC", 
    "OK",
    "+BCS:1",
    "AT+BCS=1",
    "OK"
};

const char * cc_test2[] = {
    "AT+BAC=1,2", 
    "OK",
    "AT+BCC",
    "OK",
    "+BCS:1",
    "AT+BCS=1",
    "OK"
};


const char * cc_test3[] = {
    "AT+BAC=1,2", 
    "OK",
    "AT+BCC",
    "OK",
    "+BCS:1",
    "AT+BAC=2,3", 
    "OK",
    "+BCS:3",
    "AT+BCS=3",
    "OK"
};

const char * cc_test4[] = {
    "AT+BCC", 
    "OK",
    "+BCS:1",
    "AT+BAC=2,3", 
    "OK",
    "+BCS:3",
    "AT+BCS=3",
    "OK"
};


hfp_test_item_t cc_tests[] = {
    TEST_SEQUENCE(cc_test1),
    TEST_SEQUENCE(cc_test2),
    TEST_SEQUENCE(cc_test3),
    TEST_SEQUENCE(cc_test4)
};

/* Incoming call sequence */
const char * ic_test1[] = {
    "+CIEV:3,1",
    "BCS:1",
    "AT+BCS=1",
    "OK"
};

const char * ic_alert_test1[] = {
    "ATA",
    "OK",
    "+CIEV:2,1", // call = 1
    "+CIEV:3,0", 
};

const char * ic_ag_terminates_call[] = {
    // AG terminates call
    "+CIEV:2,0"  
};

const char * ic_hf_terminates_call[] = {
    // HF terminates call
    "AT+CHUP",
    "OK",
    "+CIEV:2,0"  
};

hfp_test_item_t ic_tests[] = {
    TEST_SEQUENCE(ic_test1)
};

/* PTS test sequences - SLC Group */

const char * TC_AG_SLC_BV_01_C[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_02_C[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_03_C[] = {
    "USER:a",
    "AT+BRSF=125" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_04_C[] = {
    "USER:a",
    "AT+BRSF=125" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_05_I[] = {
    "USER:a",
    "AT+BRSF=255" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+BAC=1" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_06_I[] = {
    "USER:a",
    "AT+BRSF=255" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+BAC=1" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_07_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_09_I[] = {
    "USER:a",
    "AT+BRSF=895" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+BIND=1,99" ,
    "OK" ,
    "AT+BIND=?" ,
    "+BIND:(1,2,)" ,
    "OK" ,
    "AT+BIND?" ,
    "+BIND:1,1",
    "+BIND:2,1" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

const char * TC_AG_SLC_BV_10_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK"
};

hfp_test_item_t pts_ag_slc_tests[] = {
    TEST_SEQUENCE(TC_AG_SLC_BV_01_C),
    TEST_SEQUENCE(TC_AG_SLC_BV_02_C),
    TEST_SEQUENCE(TC_AG_SLC_BV_03_C),
    TEST_SEQUENCE(TC_AG_SLC_BV_04_C),
    TEST_SEQUENCE(TC_AG_SLC_BV_05_I),
    TEST_SEQUENCE(TC_AG_SLC_BV_06_I),
    TEST_SEQUENCE(TC_AG_SLC_BV_07_I),
    TEST_SEQUENCE(TC_AG_SLC_BV_09_I),
    TEST_SEQUENCE(TC_AG_SLC_BV_10_I)
};


const char * TC_HF_SLC_BV_01_C[] = {
    "AT+BRSF=951" ,
    "+BRSF: 511" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "USER:Q", 
    "+BSIR: 0" ,
    "USER:O", // 'AT+VGS=9" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_02_C[] = {
    "AT+BRSF=951" ,
    "+BRSF: 511" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_03_C[] = {
    "AT+BRSF=951" ,
    "+BRSF: 510" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_04_C[] = {
    "AT+BRSF=951" ,
    "+BRSF: 510" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_05_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 1023" ,
    "OK" ,
    "AT+BAC=1,2" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_06_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 1023" ,
    "OK" ,
    "AT+BAC=1,2" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_08_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 511" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_09_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 3583" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "AT+BIND=1" ,
    "OK" ,
    "AT+BIND=?" ,
    "+BIND: (1)" ,
    "OK" ,
    "AT+BIND?" ,
    "+BIND: 1,1" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

const char * TC_HF_SLC_BV_10_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 511" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "USER:Q", // "AT+VGM=9" ,
    "USER:O", // 'AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK"
};

hfp_test_item_t pts_hf_slc_tests[] = {
    TEST_SEQUENCE(TC_HF_SLC_BV_01_C),
    TEST_SEQUENCE(TC_HF_SLC_BV_02_C),
    TEST_SEQUENCE(TC_HF_SLC_BV_03_C),
    TEST_SEQUENCE(TC_HF_SLC_BV_04_C),
    TEST_SEQUENCE(TC_HF_SLC_BV_05_I),
    TEST_SEQUENCE(TC_HF_SLC_BV_06_I),
    TEST_SEQUENCE(TC_HF_SLC_BV_08_I),
    TEST_SEQUENCE(TC_HF_SLC_BV_09_I),
    TEST_SEQUENCE(TC_HF_SLC_BV_10_I),
};


/* PTS test sequences - ATA Group */

const char * TC_AG_ATA_BV_01_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c",
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "USER:C",
    "USER:B",
    "USER:t",
    "+CIEV:2,0"
};

const char * TC_AG_ATA_BV_02_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c",
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "USER:C",
    "USER:t",
    "+CIEV:2,0"
};

hfp_test_item_t pts_ag_ata_tests[] = {
    TEST_SEQUENCE(TC_AG_ATA_BV_01_I),
    TEST_SEQUENCE(TC_AG_ATA_BV_02_I)
};

const char * TC_HF_ATA_BV_01_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 511" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "AT+VGM=9" ,
    "AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK" ,
    "+CIEV: 3,1" ,
    "RING" ,
    "RING" ,
    "RING" ,
    "USER:f", // "ATA" ,
    "OK" ,
    "+CIEV: 2,1" ,
    "+CIEV: 3,0" ,
    "USER:B",
    "+CIEV: 2,0"
};

const char * TC_HF_ATA_BV_02_I[] = {
    "AT+BRSF=951" ,
    "+BRSF: 511" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND: (\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0-3)),(\"callheld\",(0-2)),(\"signal\",(0-5)),(\"roam\",(0-1)),(\"battchg\",(0-5))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND: 1,0,0,0,5,0,5" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD: (0,1,1x,2,2x,3,4)" ,
    "OK" ,
    "AT+VGM=9" ,
    "AT+VGS=9" ,
    "+BSIR: 0" ,
    "OK" ,
    "OK" ,
    "+CIEV: 3,1" ,
    "RING" ,
    "RING" ,
    "USER:f", // "ATA" ,
    "OK" ,
    "+CIEV: 2,1" ,
    "+CIEV: 3,0" ,
    "USER:t"
};

hfp_test_item_t pts_hf_ata_tests[] = {
    TEST_SEQUENCE(TC_HF_ATA_BV_01_I),
    TEST_SEQUENCE(TC_HF_ATA_BV_02_I)
};


/* PTS test sequences - TWC Group */

const char * TC_AG_TWC_BV_01_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c",
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "USER:m",
    "+CCWA: \"7654321\",129" ,
    "+CIEV:3,1" ,
    "AT+CHLD=0" ,
    "OK" ,
    "+CIEV:3,0" ,
    "USER:C",
    "+CIEV:2,0",
    "USER:t"
};

const char * TC_AG_TWC_BV_02_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c",
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "USER:m",
    "+CCWA: \"7654321\",129" ,
    "+CIEV:3,1" ,
    "AT+CHLD=1" ,
    "OK" ,
    "+CIEV:3,0" ,
    "USER:C",
    "+CIEV:2,0",
    "USER:t"
};

const char * TC_AG_TWC_BV_03_I[] = {
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c",
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "USER:m",
    "+CCWA: \"7654321\",129" ,
    "+CIEV:3,1" ,
    "AT+CHLD=2" ,
    "OK" ,
    "+CIEV:3,0" ,
    "+CIEV:7,1" ,
    "AT+CHLD=2" ,
    "OK" ,
    "+CIEV:7,1" ,
    "AT+CHLD=1" ,
    "OK" ,
    "+CIEV:7,0" ,
    "USER:C",
    "+CIEV:2,0",
    "USER:t"
};

const char * TC_AG_TWC_BV_04_I[] = {
    "USER:c",
    "USER:e",
    "USER:m",
    "USER:e",
    "USER:a",
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,1,0,3,5,0,1" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "AT+CHLD=3" ,
    "OK" ,
    "USER:C",
    "+CIEV:7,0" ,
    "+CIEV:2,0",
    "USER:t"
};

const char * TC_AG_TWC_BV_05_I[] = {
    "USER:a" ,
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c" ,
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "AT+BLDN" ,
    "+CIEV:7,2" ,
    "OK" ,
    "+CIEV:3,2" ,
    "USER:j" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "+CIEV:7,1" ,
    "AT+CHLD=1" ,
    "OK" ,
    "+CIEV:7,0" ,
    "USER:C" ,
    "+CIEV:2,0" ,
    "USER:t"
};

const char * TC_AG_TWC_BV_06_I[] = {
    "USER:a" ,
    "AT+BRSF=127" ,
    "+BRSF:4079" ,
    "OK" ,
    "AT+CIND=?" ,
    "+CIND:(\"service\",(0,1)),(\"call\",(0,1)),(\"callsetup\",(0,3)),(\"battchg\",(0,5)),(\"signal\",(0,5)),(\"roam\",(0,1)),(\"callheld\",(0,2))" ,
    "OK" ,
    "AT+CIND?" ,
    "+CIND:1,0,0,3,5,0,0" ,
    "OK" ,
    "AT+CMER=3,0,0,1" ,
    "OK" ,
    "AT+CHLD=?" ,
    "+CHLD:(1,1x,2,2x,3)" ,
    "OK" ,
    "AT+VGS=9" ,
    "OK" ,
    "AT+VGM=9" ,
    "OK" ,
    "AT+CLIP=1" ,
    "OK" ,
    "AT+CCWA=1" ,
    "OK" ,
    "AT+CMEE=1" ,
    "OK" ,
    "USER:c" ,
    "+CIEV:3,1" ,
    "RING" ,
    "+CLIP: \"1234567\",129" ,
    "ATA" ,
    "OK" ,
    "+CIEV:2,1" ,
    "+CIEV:3,0" ,
    "USER:m" ,
    "+CCWA: \"7654321\",129" ,
    "+CIEV:3,1" ,
    "AT+CHLD=2" ,
    "OK" ,
    "+CIEV:3,0" ,
    "+CIEV:7,1" ,
    "AT+CHLD=4" ,
    "OK" ,
    "+CIEV:2,0" ,
    "+CIEV:7,0" ,
    "USER:B" ,
    "USER:A"
};

hfp_test_item_t pts_ag_twc_tests[] = {
    TEST_SEQUENCE(TC_AG_TWC_BV_01_I),
    TEST_SEQUENCE(TC_AG_TWC_BV_02_I),
    TEST_SEQUENCE(TC_AG_TWC_BV_03_I),
    TEST_SEQUENCE(TC_AG_TWC_BV_04_I),
    TEST_SEQUENCE(TC_AG_TWC_BV_05_I),
    TEST_SEQUENCE(TC_AG_TWC_BV_06_I)
};


const char * TC_HF_TWC_BV_01_I[] = {

};
const char * TC_HF_TWC_BV_02_I[] = {

};
const char * TC_HF_TWC_BV_03_I[] = {

};
const char * TC_HF_TWC_BV_04_I[] = {

};
const char * TC_HF_TWC_BV_05_I[] = {

};
const char * TC_HF_TWC_BV_06_I[] = {

};
hfp_test_item_t pts_hf_twc_tests[] = {
    TEST_SEQUENCE(TC_HF_TWC_BV_01_I),
    TEST_SEQUENCE(TC_HF_TWC_BV_02_I),
    TEST_SEQUENCE(TC_HF_TWC_BV_03_I),
    TEST_SEQUENCE(TC_HF_TWC_BV_04_I),
    TEST_SEQUENCE(TC_HF_TWC_BV_05_I),
    TEST_SEQUENCE(TC_HF_TWC_BV_06_I)
};


/* PTS test sequences - ECS Group */
const char * TC_AG_ECS_BV_01_I[] = {};
const char * TC_AG_ECS_BV_02_I[] = {};
const char * TC_AG_ECS_BV_03_I[] = {};


hfp_test_item_t pts_ag_ecs_tests[] = {
    TEST_SEQUENCE(TC_AG_ECS_BV_01_I),
    TEST_SEQUENCE(TC_AG_ECS_BV_02_I),
    TEST_SEQUENCE(TC_AG_ECS_BV_03_I)
};


const char * TC_HF_ECS_BV_01_I[] = {};
const char * TC_HF_ECS_BV_02_I[] = {};
const char * TC_HF_ECS_BV_03_I[] = {};

hfp_test_item_t pts_hf_ecs_tests[] = {
    TEST_SEQUENCE(TC_HF_ECS_BV_01_I),
    TEST_SEQUENCE(TC_HF_ECS_BV_02_I),
    TEST_SEQUENCE(TC_HF_ECS_BV_03_I)
};


/* PTS test sequences - ECC Group */
const char * TC_AG_ECC_BV_01_I[] = {};
const char * TC_AG_ECC_BV_02_I[] = {};
const char * TC_AG_ECC_BV_03_I[] = {};
const char * TC_AG_ECC_BV_04_I[] = {};

hfp_test_item_t pts_ag_ecc_tests[] = {
    TEST_SEQUENCE(TC_AG_ECC_BV_01_I),
    TEST_SEQUENCE(TC_AG_ECC_BV_02_I),
    TEST_SEQUENCE(TC_AG_ECC_BV_03_I),
    TEST_SEQUENCE(TC_AG_ECC_BV_04_I)
};

const char * TC_HF_ECC_BV_01_I[] = {};
const char * TC_HF_ECC_BV_02_I[] = {};
const char * TC_HF_ECC_BV_03_I[] = {};
const char * TC_HF_ECC_BV_04_I[] = {};

hfp_test_item_t pts_hf_ecc_tests[] = {
    TEST_SEQUENCE(TC_HF_ECC_BV_01_I),
    TEST_SEQUENCE(TC_HF_ECC_BV_02_I),
    TEST_SEQUENCE(TC_HF_ECC_BV_03_I),
    TEST_SEQUENCE(TC_HF_ECC_BV_04_I)
};


/* PTS test sequences - RHH Group */
const char * TC_AG_RHH_BV_01_I[] = {};
const char * TC_AG_RHH_BV_02_I[] = {};
const char * TC_AG_RHH_BV_03_I[] = {};
const char * TC_AG_RHH_BV_04_I[] = {};
const char * TC_AG_RHH_BV_05_I[] = {};
const char * TC_AG_RHH_BV_06_I[] = {};
const char * TC_AG_RHH_BV_07_I[] = {};
const char * TC_AG_RHH_BV_08_I[] = {};

hfp_test_item_t pts_ag_rhh_tests[] = {
    TEST_SEQUENCE(TC_AG_RHH_BV_01_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_02_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_03_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_04_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_05_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_06_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_07_I),
    TEST_SEQUENCE(TC_AG_RHH_BV_08_I)
};

const char * TC_HF_RHH_BV_01_I[] = {};
const char * TC_HF_RHH_BV_02_I[] = {};
const char * TC_HF_RHH_BV_03_I[] = {};
const char * TC_HF_RHH_BV_04_I[] = {};
const char * TC_HF_RHH_BV_05_I[] = {};
const char * TC_HF_RHH_BV_06_I[] = {};
const char * TC_HF_RHH_BV_07_I[] = {};
const char * TC_HF_RHH_BV_08_I[] = {};

hfp_test_item_t pts_hf_rhh_tests[] = {
    TEST_SEQUENCE(TC_HF_RHH_BV_01_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_02_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_03_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_04_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_05_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_06_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_07_I),
    TEST_SEQUENCE(TC_HF_RHH_BV_08_I)
};

/////////
static int test_item_size = sizeof(hfp_test_item_t);

// CC
int hfp_cc_tests_size(){ return sizeof(cc_tests) /test_item_size;}
hfp_test_item_t * hfp_cc_tests(){ return cc_tests;}
hfp_test_item_t * default_hfp_cc_test(){ return &cc_tests[0];}

// PTS - SLC Group
int hfp_pts_ag_slc_tests_size(){ return sizeof(pts_ag_slc_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_ag_slc_tests(){ return pts_ag_slc_tests;}

int hfp_pts_hf_slc_tests_size(){ return sizeof(pts_hf_slc_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_hf_slc_tests(){ return pts_hf_slc_tests;}

// PTS - ATA Group
int hfp_pts_ag_ata_tests_size(){ return sizeof(pts_ag_ata_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_ag_ata_tests(){ return pts_ag_ata_tests;}

int hfp_pts_hf_ata_tests_size(){ return sizeof(pts_hf_ata_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_hf_ata_tests(){ return pts_hf_ata_tests;}

// PTS - TWC Group
int hfp_pts_ag_twc_tests_size(){ return sizeof(pts_ag_twc_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_ag_twc_tests(){ return pts_ag_twc_tests;}
int hfp_pts_hf_twc_tests_size(){ return sizeof(pts_hf_twc_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_hf_twc_tests(){ return pts_hf_twc_tests;}

// PTS - ECS Group
int hfp_pts_ag_ecs_tests_size(){ return sizeof(pts_ag_ecs_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_ag_ecs_tests(){ return pts_ag_ecs_tests;}
int hfp_pts_hf_ecs_tests_size(){ return sizeof(pts_hf_ecs_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_hf_ecs_tests(){ return pts_hf_ecs_tests;}

// PTS - ECC Group
int hfp_pts_ag_ecc_tests_size(){ return sizeof(pts_ag_ecc_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_ag_ecc_tests(){ return pts_ag_ecc_tests;}
int hfp_pts_hf_ecc_tests_size(){ return sizeof(pts_hf_ecc_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_hf_ecc_tests(){ return pts_hf_ecc_tests;}

// PTS - RHH Group
int hfp_pts_ag_rhh_tests_size(){ return sizeof(pts_ag_rhh_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_ag_rhh_tests(){ return pts_ag_rhh_tests;}
int hfp_pts_hf_rhh_tests_size(){ return sizeof(pts_hf_rhh_tests)/test_item_size;}
hfp_test_item_t * hfp_pts_hf_rhh_tests(){ return pts_hf_rhh_tests;}


 
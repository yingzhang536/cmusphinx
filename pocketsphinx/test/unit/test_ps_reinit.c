#include <pocketsphinx.h>
#include <stdio.h>
#include <string.h>

#include "test_macros.h"

int
main(int argc, char *argv[])
{
	ps_decoder_t *ps;
	cmd_ln_t *config;

	TEST_ASSERT(config =
		    cmd_ln_init(NULL, ps_args(), TRUE,
				"-hmm", MODELDIR "/hmm/en_US/wsj1",
				"-lm", MODELDIR "/lm/en_US/wsj/wlist5o.3e-7.vp.tg.lm.DMP",
				"-dict", MODELDIR "/lm/en_US/cmudict.0.6d",
				"-fwdtree", "yes",
				"-fwdflat", "yes",
				"-bestpath", "yes",
				"-input_endian", "little",
				"-samprate", "16000", NULL));
	TEST_ASSERT(ps = ps_init(config));

	TEST_ASSERT(config =
		    cmd_ln_init(NULL, ps_args(), TRUE,
				"-hmm", MODELDIR "/hmm/en/tidigits",
				"-lm", MODELDIR "/lm/en/tidigits/tidigits.lm.DMP",
				"-dict", MODELDIR "/lm/en/tidigits/tidigits.dic",
				"-fwdtree", "yes",
				"-fwdflat", "yes",
				"-bestpath", "yes",
				"-input_endian", "little",
				"-samprate", "16000", NULL));
	TEST_EQUAL(0, ps_reinit(ps, config));

	ps_free(ps);

	return 0;
}

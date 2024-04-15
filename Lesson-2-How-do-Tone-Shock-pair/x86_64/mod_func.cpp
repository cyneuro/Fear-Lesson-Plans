#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _AMPA_NMDA_LTP_reg(void);
extern void _AMPA_NMDA_STP_reg(void);
extern void _Gfluct_new_exc_reg(void);
extern void _Gfluct_new_inh_reg(void);
extern void _cadyn_reg(void);
extern void _capool_reg(void);
extern void _currentclamp_reg(void);
extern void _h_reg(void);
extern void _im_reg(void);
extern void _kadist_reg(void);
extern void _kaprox_reg(void);
extern void _kdrca1_reg(void);
extern void _leak_reg(void);
extern void _na3_reg(void);
extern void _nap_reg(void);
extern void _pyr2pyr_reg(void);
extern void _sahp_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"modfiles/AMPA_NMDA_LTP.mod\"");
    fprintf(stderr, " \"modfiles/AMPA_NMDA_STP.mod\"");
    fprintf(stderr, " \"modfiles/Gfluct_new_exc.mod\"");
    fprintf(stderr, " \"modfiles/Gfluct_new_inh.mod\"");
    fprintf(stderr, " \"modfiles/cadyn.mod\"");
    fprintf(stderr, " \"modfiles/capool.mod\"");
    fprintf(stderr, " \"modfiles/currentclamp.mod\"");
    fprintf(stderr, " \"modfiles/h.mod\"");
    fprintf(stderr, " \"modfiles/im.mod\"");
    fprintf(stderr, " \"modfiles/kadist.mod\"");
    fprintf(stderr, " \"modfiles/kaprox.mod\"");
    fprintf(stderr, " \"modfiles/kdrca1.mod\"");
    fprintf(stderr, " \"modfiles/leak.mod\"");
    fprintf(stderr, " \"modfiles/na3.mod\"");
    fprintf(stderr, " \"modfiles/nap.mod\"");
    fprintf(stderr, " \"modfiles/pyr2pyr.mod\"");
    fprintf(stderr, " \"modfiles/sahp.mod\"");
    fprintf(stderr, "\n");
  }
  _AMPA_NMDA_LTP_reg();
  _AMPA_NMDA_STP_reg();
  _Gfluct_new_exc_reg();
  _Gfluct_new_inh_reg();
  _cadyn_reg();
  _capool_reg();
  _currentclamp_reg();
  _h_reg();
  _im_reg();
  _kadist_reg();
  _kaprox_reg();
  _kdrca1_reg();
  _leak_reg();
  _na3_reg();
  _nap_reg();
  _pyr2pyr_reg();
  _sahp_reg();
}

#if defined(__cplusplus)
}
#endif

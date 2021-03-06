/*
  Copyright (c) 2007-2016 Red Hat, Inc. <http://www.redhat.com>
  This file is part of GlusterFS.

  This file is licensed to you under your choice of the GNU Lesser
  General Public License, version 3 or any later version (LGPLv3 or
  later), or the GNU General Public License, version 2 (GPLv2), in all
  cases as published by the Free Software Foundation.
*/

#include "compat.h"

#if defined(__GNUC__)
#if __GNUC__ >= 4
#if !defined(__clang__)
#if !defined(__NetBSD__)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
#else
#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-value"
#endif
#endif
#endif

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NLM4_XDR_H_RPCGEN
#define _NLM4_XDR_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#include "xdr-common.h"
#define MAXNETOBJ_SZ 1024
#define LM_MAXSTRLEN 1024
#define MAXNAMELEN 1025

typedef struct {
	u_int nlm4_netobj_len;
	char *nlm4_netobj_val;
} nlm4_netobj;
/*
 * The following enums are actually bit encoded for efficient
 * boolean algebra.... DON'T change them.....
 */

enum fsh_mode {
	fsm_DN = 0,
	fsm_DR = 1,
	fsm_DW = 2,
	fsm_DRW = 3,
};
typedef enum fsh_mode fsh_mode;

enum fsh_access {
	fsa_NONE = 0,
	fsa_R = 1,
	fsa_W = 2,
	fsa_RW = 3,
};
typedef enum fsh_access fsh_access;
/* definitions for NLM version 4 */

enum nlm4_stats {
	nlm4_granted = 0,
	nlm4_denied = 1,
	nlm4_denied_nolock = 2,
	nlm4_blocked = 3,
	nlm4_denied_grace_period = 4,
	nlm4_deadlck = 5,
	nlm4_rofs = 6,
	nlm4_stale_fh = 7,
	nlm4_fbig = 8,
	nlm4_failed = 9,
};
typedef enum nlm4_stats nlm4_stats;

struct nlm4_stat {
	nlm4_stats stat;
};
typedef struct nlm4_stat nlm4_stat;

struct nlm4_holder {
	bool_t exclusive;
	u_int32_t svid;
	nlm4_netobj oh;
	u_int64_t l_offset;
	u_int64_t l_len;
};
typedef struct nlm4_holder nlm4_holder;

struct nlm4_lock {
	char *caller_name;
	nlm4_netobj fh;
	nlm4_netobj oh;
	u_int32_t svid;
	u_int64_t l_offset;
	u_int64_t l_len;
};
typedef struct nlm4_lock nlm4_lock;

struct nlm4_share {
	char *caller_name;
	nlm4_netobj fh;
	nlm4_netobj oh;
	fsh_mode mode;
	fsh_access access;
};
typedef struct nlm4_share nlm4_share;

struct nlm4_testrply {
	nlm4_stats stat;
	union {
		struct nlm4_holder holder;
	} nlm4_testrply_u;
};
typedef struct nlm4_testrply nlm4_testrply;

struct nlm4_testres {
	nlm4_netobj cookie;
	nlm4_testrply stat;
};
typedef struct nlm4_testres nlm4_testres;

struct nlm4_testargs {
	nlm4_netobj cookie;
	bool_t exclusive;
	struct nlm4_lock alock;
};
typedef struct nlm4_testargs nlm4_testargs;

struct nlm4_res {
	nlm4_netobj cookie;
	nlm4_stat stat;
};
typedef struct nlm4_res nlm4_res;

struct nlm4_lockargs {
	nlm4_netobj cookie;
	bool_t block;
	bool_t exclusive;
	struct nlm4_lock alock;
	bool_t reclaim;
	int32_t state;
};
typedef struct nlm4_lockargs nlm4_lockargs;

struct nlm4_cancargs {
	nlm4_netobj cookie;
	bool_t block;
	bool_t exclusive;
	struct nlm4_lock alock;
};
typedef struct nlm4_cancargs nlm4_cancargs;

struct nlm4_unlockargs {
	nlm4_netobj cookie;
	struct nlm4_lock alock;
};
typedef struct nlm4_unlockargs nlm4_unlockargs;

struct nlm4_shareargs {
	nlm4_netobj cookie;
	nlm4_share share;
	bool_t reclaim;
};
typedef struct nlm4_shareargs nlm4_shareargs;

struct nlm4_shareres {
	nlm4_netobj cookie;
	nlm4_stats stat;
	int32_t sequence;
};
typedef struct nlm4_shareres nlm4_shareres;

struct nlm4_freeallargs {
	char *name;
	uint32_t state;
};
typedef struct nlm4_freeallargs nlm4_freeallargs;

struct nlm_sm_status {
	char *mon_name;
	int state;
	char priv[16];
};
typedef struct nlm_sm_status nlm_sm_status;

#define NLMCBK_PROGRAM 100021
#define NLMCBK_V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define NLMCBK_SM_NOTIFY 16
extern  void * nlmcbk_sm_notify_1(struct nlm_sm_status *, CLIENT *);
extern  void * nlmcbk_sm_notify_1_svc(struct nlm_sm_status *, struct svc_req *);
extern int nlmcbk_program_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define NLMCBK_SM_NOTIFY 16
extern  void * nlmcbk_sm_notify_1();
extern  void * nlmcbk_sm_notify_1_svc();
extern int nlmcbk_program_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_nlm4_netobj (XDR *, nlm4_netobj*);
extern  bool_t xdr_fsh_mode (XDR *, fsh_mode*);
extern  bool_t xdr_fsh_access (XDR *, fsh_access*);
extern  bool_t xdr_nlm4_stats (XDR *, nlm4_stats*);
extern  bool_t xdr_nlm4_stat (XDR *, nlm4_stat*);
extern  bool_t xdr_nlm4_holder (XDR *, nlm4_holder*);
extern  bool_t xdr_nlm4_lock (XDR *, nlm4_lock*);
extern  bool_t xdr_nlm4_share (XDR *, nlm4_share*);
extern  bool_t xdr_nlm4_testrply (XDR *, nlm4_testrply*);
extern  bool_t xdr_nlm4_testres (XDR *, nlm4_testres*);
extern  bool_t xdr_nlm4_testargs (XDR *, nlm4_testargs*);
extern  bool_t xdr_nlm4_res (XDR *, nlm4_res*);
extern  bool_t xdr_nlm4_lockargs (XDR *, nlm4_lockargs*);
extern  bool_t xdr_nlm4_cancargs (XDR *, nlm4_cancargs*);
extern  bool_t xdr_nlm4_unlockargs (XDR *, nlm4_unlockargs*);
extern  bool_t xdr_nlm4_shareargs (XDR *, nlm4_shareargs*);
extern  bool_t xdr_nlm4_shareres (XDR *, nlm4_shareres*);
extern  bool_t xdr_nlm4_freeallargs (XDR *, nlm4_freeallargs*);
extern  bool_t xdr_nlm_sm_status (XDR *, nlm_sm_status*);

#else /* K&R C */
extern bool_t xdr_nlm4_netobj ();
extern bool_t xdr_fsh_mode ();
extern bool_t xdr_fsh_access ();
extern bool_t xdr_nlm4_stats ();
extern bool_t xdr_nlm4_stat ();
extern bool_t xdr_nlm4_holder ();
extern bool_t xdr_nlm4_lock ();
extern bool_t xdr_nlm4_share ();
extern bool_t xdr_nlm4_testrply ();
extern bool_t xdr_nlm4_testres ();
extern bool_t xdr_nlm4_testargs ();
extern bool_t xdr_nlm4_res ();
extern bool_t xdr_nlm4_lockargs ();
extern bool_t xdr_nlm4_cancargs ();
extern bool_t xdr_nlm4_unlockargs ();
extern bool_t xdr_nlm4_shareargs ();
extern bool_t xdr_nlm4_shareres ();
extern bool_t xdr_nlm4_freeallargs ();
extern bool_t xdr_nlm_sm_status ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NLM4_XDR_H_RPCGEN */

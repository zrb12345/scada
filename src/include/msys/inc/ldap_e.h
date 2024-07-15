/**
 ********************************************************************************
 * @file     ldap_e.h
 * @author   reno
 *
 * @brief This file is a wrapper for the VxWorks 7 ldap functions.
 *
 ********************************************************************************
 * COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2017
 *******************************************************************************/

#ifndef _LDAP_E_H_
#define _LDAP_E_H_

#include <vxWorks.h>
#include <mtypes.h>
#include <sys/times.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @addtogroup SYS-LDAP-DEF
 * @{
 */

/**
 * @name General LDAP defines
 * @{
 */
#define sys_LDAP_VERSION3   3

#define sys_LDAP_VERSION_MIN   sys_LDAP_VERSION3
#define sys_LDAP_VERSION       sys_LDAP_VERSION3
#define sys_LDAP_VERSION_MAX   sys_LDAP_VERSION3


#define sys_LDAP_PORT       389      /**< ldap:///      default LDAP port */
#define sys_LDAPS_PORT      636      /**< ldaps:///   default LDAP over TLS port */

#define sys_LDAP_ROOT_DSE               ""
#define sys_LDAP_NO_ATTRS               "1.1"
#define sys_LDAP_ALL_USER_ATTRIBUTES    "*"
#define sys_LDAP_ALL_OPERATIONAL_ATTRIBUTES   "+" /**< RFC 3673 */

/* RFC 4511:  maxInt INTEGER ::= 2147483647 -- (2^^31 - 1) -- */
#define sys_LDAP_MAXINT (2147483647)
/** @} */


/**
 * @anchor sys_LDAP_OPT_
 */

/**
 * @name LDAP options
 * 0x0000 - 0x0fff reserved for api options<br>
 * 0x1000 - 0x3fff reserved for api extended options<br>
 * 0x4000 - 0x7fff reserved for private and experimental option<br>
 * @{
 */
#define sys_LDAP_OPT_API_INFO             0x0000
#define sys_LDAP_OPT_DESC                 0x0001 /**< historic */
#define sys_LDAP_OPT_DEREF                0x0002
#define sys_LDAP_OPT_SIZELIMIT            0x0003
#define sys_LDAP_OPT_TIMELIMIT            0x0004
/* 0x05 - 0x07 not defined */
#define sys_LDAP_OPT_REFERRALS            0x0008
#define sys_LDAP_OPT_RESTART              0x0009
/* 0x0a - 0x10 not defined */
#define sys_LDAP_OPT_PROTOCOL_VERSION     0x0011
#define sys_LDAP_OPT_SERVER_CONTROLS      0x0012
#define sys_LDAP_OPT_CLIENT_CONTROLS      0x0013
/* 0x14 not defined */
#define sys_LDAP_OPT_API_FEATURE_INFO     0x0015
/* 0x16 - 0x2f not defined */
#define sys_LDAP_OPT_HOST_NAME            0x0030
#define sys_LDAP_OPT_RESULT_CODE          0x0031
#define sys_LDAP_OPT_ERROR_NUMBER         sys_LDAP_OPT_RESULT_CODE
#define sys_LDAP_OPT_DIAGNOSTIC_MESSAGE   0x0032
#define sys_LDAP_OPT_ERROR_STRING         sys_LDAP_OPT_DIAGNOSTIC_MESSAGE
#define sys_LDAP_OPT_MATCHED_DN           0x0033
/* 0x0034 - 0x3fff not defined */
/* 0x0091 used by Microsoft for sys_LDAP_OPT_AUTO_RECONNECT */
#define sys_LDAP_OPT_SSPI_FLAGS           0x0092
/* 0x0093 used by Microsoft for sys_LDAP_OPT_SSL_INFO */
/* 0x0094 used by Microsoft for sys_LDAP_OPT_REF_DEREF_CONN_PER_MSG */
#define sys_LDAP_OPT_SIGN                 0x0095
#define sys_LDAP_OPT_ENCRYPT              0x0096
#define sys_LDAP_OPT_SASL_METHOD          0x0097
/* 0x0098 used by Microsoft for sys_LDAP_OPT_AREC_EXCLUSIVE */
#define sys_LDAP_OPT_SECURITY_CONTEXT     0x0099
/* 0x009A used by Microsoft for sys_LDAP_OPT_ROOTDSE_CACHE */
/* 0x009B - 0x3fff not defined */
/** @} */

/* private and experimental options */
/**
 * @name OpenLDAP specific options
 * @{
 */
#define sys_LDAP_OPT_DEBUG_LEVEL        0x5001   /**< debug level */
#define sys_LDAP_OPT_TIMEOUT            0x5002   /**< default timeout */
#define sys_LDAP_OPT_REFHOPLIMIT        0x5003   /**< ref hop limit */
#define sys_LDAP_OPT_NETWORK_TIMEOUT    0x5005   /**< socket level timeout */
#define sys_LDAP_OPT_URI                0x5006
#define sys_LDAP_OPT_REFERRAL_URLS      0x5007   /**< Referral URLs */
#define sys_LDAP_OPT_SOCKBUF            0x5008   /**< sockbuf */
#define sys_LDAP_OPT_DEFBASE            0x5009   /**< searchbase */
#define sys_LDAP_OPT_CONNECT_ASYNC      0x5010   /**< create connections asynchronously */
#define sys_LDAP_OPT_CONNECT_CB         0x5011   /**< connection callbacks */
#define sys_LDAP_OPT_SESSION_REFCNT     0x5012   /**< session reference count */
/** @} */

/**
 * @name OpenLDAP TLS options
 * @{
 */
#define sys_LDAP_OPT_X_TLS                0x6000
#define sys_LDAP_OPT_X_TLS_CTX            0x6001   /**< OpenSSL CTX* */
#define sys_LDAP_OPT_X_TLS_CACERTFILE     0x6002
#define sys_LDAP_OPT_X_TLS_CACERTDIR      0x6003
#define sys_LDAP_OPT_X_TLS_CERTFILE       0x6004
#define sys_LDAP_OPT_X_TLS_KEYFILE        0x6005
#define sys_LDAP_OPT_X_TLS_REQUIRE_CERT   0x6006
#define sys_LDAP_OPT_X_TLS_PROTOCOL_MIN   0x6007
#define sys_LDAP_OPT_X_TLS_CIPHER_SUITE   0x6008
#define sys_LDAP_OPT_X_TLS_RANDOM_FILE    0x6009
#define sys_LDAP_OPT_X_TLS_SSL_CTX        0x600a   /**< OpenSSL SSL* */
#define sys_LDAP_OPT_X_TLS_CRLCHECK       0x600b
#define sys_LDAP_OPT_X_TLS_CONNECT_CB     0x600c
#define sys_LDAP_OPT_X_TLS_CONNECT_ARG    0x600d
#define sys_LDAP_OPT_X_TLS_DHFILE         0x600e
#define sys_LDAP_OPT_X_TLS_NEWCTX         0x600f
#define sys_LDAP_OPT_X_TLS_CRLFILE        0x6010   /**< GNUtls only */
#define sys_LDAP_OPT_X_TLS_PACKAGE        0x6011

#define sys_LDAP_OPT_X_TLS_NEVER    0
#define sys_LDAP_OPT_X_TLS_HARD     1
#define sys_LDAP_OPT_X_TLS_DEMAND   2
#define sys_LDAP_OPT_X_TLS_ALLOW    3
#define sys_LDAP_OPT_X_TLS_TRY      4

#define sys_LDAP_OPT_X_TLS_CRL_NONE   0
#define sys_LDAP_OPT_X_TLS_CRL_PEER   1
#define sys_LDAP_OPT_X_TLS_CRL_ALL    2
/** @} */

/**
 * @name for sys_LDAP_OPT_X_TLS_PROTOCOL_MIN
 * @{
 */
#define sys_LDAP_OPT_X_TLS_PROTOCOL(maj,min)   (((maj) << 8) + (min))
#define sys_LDAP_OPT_X_TLS_PROTOCOL_SSL2       (2 << 8)
#define sys_LDAP_OPT_X_TLS_PROTOCOL_SSL3       (3 << 8)
#define sys_LDAP_OPT_X_TLS_PROTOCOL_TLS1_0     ((3 << 8) + 1)
#define sys_LDAP_OPT_X_TLS_PROTOCOL_TLS1_1     ((3 << 8) + 2)
#define sys_LDAP_OPT_X_TLS_PROTOCOL_TLS1_2     ((3 << 8) + 3)
/** @} */

/**
 * @name OpenLDAP SASL options
 * @{
 */
#define sys_LDAP_OPT_X_SASL_MECH          0x6100
#define sys_LDAP_OPT_X_SASL_REALM         0x6101
#define sys_LDAP_OPT_X_SASL_AUTHCID       0x6102
#define sys_LDAP_OPT_X_SASL_AUTHZID       0x6103
#define sys_LDAP_OPT_X_SASL_SSF           0x6104 /**< read-only */
#define sys_LDAP_OPT_X_SASL_SSF_EXTERNAL  0x6105 /**< write-only */
#define sys_LDAP_OPT_X_SASL_SECPROPS      0x6106 /**< write-only */
#define sys_LDAP_OPT_X_SASL_SSF_MIN       0x6107
#define sys_LDAP_OPT_X_SASL_SSF_MAX       0x6108
#define sys_LDAP_OPT_X_SASL_MAXBUFSIZE    0x6109
#define sys_LDAP_OPT_X_SASL_MECHLIST      0x610a /**< read-only */
#define sys_LDAP_OPT_X_SASL_NOCANON       0x610b
#define sys_LDAP_OPT_X_SASL_USERNAME      0x610c /**< read-only */
#define sys_LDAP_OPT_X_SASL_GSS_CREDS     0x610d
/** @} */

/**
 * @name OpenLDAP GSSAPI options
 * @{
 */
#define sys_LDAP_OPT_X_GSSAPI_DO_NOT_FREE_CONTEXT      0x6200
#define sys_LDAP_OPT_X_GSSAPI_ALLOW_REMOTE_PRINCIPAL   0x6201
/** @} */

/**
 * @name OpenLDAP per connection tcp-keepalive settings.
 * (Linux only, ignored where unsupported)
 * @{
 */
#define sys_LDAP_OPT_X_KEEPALIVE_IDLE        0x6300
#define sys_LDAP_OPT_X_KEEPALIVE_PROBES      0x6301
#define sys_LDAP_OPT_X_KEEPALIVE_INTERVAL    0x6302
/** @} */

/**
 * @name Private API Extensions -- reserved for application use.
 * @{
 */
#define sys_LDAP_OPT_PRIVATE_EXTENSION_BASE 0x7000  /**< Private API inclusive */
/** @} */

/**
 * @name sys_ldap_GetOption() and sys_ldap_SetOption() return values.
 * As later versions may return other values indicating
 * failure, current applications should only compare returned
 * value against sys_LDAP_OPT_SUCCESS.
 * @{
 */
#define sys_LDAP_OPT_SUCCESS      0
#define   sys_LDAP_OPT_ERROR      (-1)
/** @} */

/**
 * @name option on/off values
 * @{
 */
#define sys_LDAP_OPT_ON      ((void *) &ber_pvt_opt_on)
#define sys_LDAP_OPT_OFF     ((void *) 0)
/** @} */



/**
 *  structure for returning a sequence of octet strings + length
 */
typedef struct sys_berval {
    long  bv_len;   /**< Length */
    char  *bv_val;  /**< Value */
} sys_BerValue;

/**
 * Opaque structure used to maintain state information used in encoding and decoding
 */
typedef struct sys_berelement sys_BerElement;

/**
 * @name String representation of a distinguished name into its components,
 *       which are stored in dn as sys_ldap_ava structures, arranged in sys_LDAPAVA, sys_LDAPRDN,
 *       and LDAPDN terms.
 * @{
 */
typedef struct sys_ldap_ava {
    struct sys_berval la_attr;
    struct sys_berval la_value;
    unsigned la_flags;
#define sys_LDAP_AVA_NULL            0x0000U
#define sys_LDAP_AVA_STRING          0x0001U
#define sys_LDAP_AVA_BINARY          0x0002U
#define sys_LDAP_AVA_NONPRINTABLE    0x0004U
#define sys_LDAP_AVA_FREE_ATTR       0x0010U
#define sys_LDAP_AVA_FREE_VALUE      0x0020U

    void *la_private;
} sys_LDAPAVA;

typedef sys_LDAPAVA** sys_LDAPRDN;
typedef sys_LDAPRDN* sys_LDAPDN;
/** @} */

/**
 * @name DN formats
 * @{
 */
#define sys_LDAP_DN_FORMAT_LDAP         0x0000U
#define sys_LDAP_DN_FORMAT_LDAPV3       0x0010U
#define sys_LDAP_DN_FORMAT_LDAPV2       0x0020U
#define sys_LDAP_DN_FORMAT_DCE          0x0030U
#define sys_LDAP_DN_FORMAT_UFN          0x0040U  /**< dn2str only */
#define sys_LDAP_DN_FORMAT_AD_CANONICAL 0x0050U  /**< dn2str only */
#define sys_LDAP_DN_FORMAT_LBER         0x00F0U  /**< for testing only */
#define sys_LDAP_DN_FORMAT_MASK         0x00F0U
/** @} */

/**
 * @name DN flags
 * @{
 */
#define sys_LDAP_DN_PRETTY              0x0100U
#define sys_LDAP_DN_SKIP                0x0200U
#define sys_LDAP_DN_P_NOLEADTRAILSPACES 0x1000U
#define sys_LDAP_DN_P_NOSPACEAFTERRDN   0x2000U
#define sys_LDAP_DN_PEDANTIC            0xF000U
/** @} */

/**
 * LDAP Control structure
 */
typedef struct sys_ldapcontrol {
    char *             ldctl_oid;            /**< numericoid of control */
    struct sys_berval    ldctl_value;        /**< encoded value of control */
    char                ldctl_iscritical;    /**< criticality */
} sys_LDAPControl;

/**
 * @name LDAP Controls
 * @{
 */
/* standard track controls */
#define sys_LDAP_CONTROL_MANAGEDSAIT    "2.16.840.1.113730.3.4.2"      /**< RFC 3296 */
#define sys_LDAP_CONTROL_PROXY_AUTHZ    "2.16.840.1.113730.3.4.18"     /**< RFC 4370 */
#define sys_LDAP_CONTROL_SUBENTRIES     "1.3.6.1.4.1.4203.1.10.1"      /**< RFC 3672 */

#define sys_LDAP_CONTROL_VALUESRETURNFILTER "1.2.826.0.1.3344810.2.3"  /**< RFC 3876 */

#define sys_LDAP_CONTROL_ASSERT             "1.3.6.1.1.12"             /**< RFC 4528 */
#define sys_LDAP_CONTROL_PRE_READ           "1.3.6.1.1.13.1"           /**< RFC 4527 */
#define sys_LDAP_CONTROL_POST_READ          "1.3.6.1.1.13.2"           /**< RFC 4527 */

#define sys_LDAP_CONTROL_SORTREQUEST    "1.2.840.113556.1.4.473"       /**< RFC 2891 */
#define sys_LDAP_CONTROL_SORTRESPONSE   "1.2.840.113556.1.4.474"       /**< RFC 2891 */

/*    non-standard track controls */
#define sys_LDAP_CONTROL_PAGEDRESULTS    "1.2.840.113556.1.4.319"      /**< RFC 2696 */
/** @} */

/**
 * @name LDAP Content Synchronization Operation -- RFC 4533
 * @{
 */
#define sys_LDAP_SYNC_OID              "1.3.6.1.4.1.4203.1.9.1"
#define sys_LDAP_CONTROL_SYNC          sys_LDAP_SYNC_OID ".1"
#define sys_LDAP_CONTROL_SYNC_STATE    sys_LDAP_SYNC_OID ".2"
#define sys_LDAP_CONTROL_SYNC_DONE     sys_LDAP_SYNC_OID ".3"
#define sys_LDAP_SYNC_INFO             sys_LDAP_SYNC_OID ".4"

#define sys_LDAP_SYNC_NONE                    0x00
#define sys_LDAP_SYNC_REFRESH_ONLY            0x01
#define sys_LDAP_SYNC_RESERVED                0x02
#define sys_LDAP_SYNC_REFRESH_AND_PERSIST     0x03

#define sys_LDAP_SYNC_REFRESH_PRESENTS        0
#define sys_LDAP_SYNC_REFRESH_DELETES         1

#define sys_LDAP_TAG_SYNC_NEW_COOKIE        0x80U
#define sys_LDAP_TAG_SYNC_REFRESH_DELETE    0xa1U
#define sys_LDAP_TAG_SYNC_REFRESH_PRESENT   0xa2U
#define    sys_LDAP_TAG_SYNC_ID_SET         0xa3U

#define sys_LDAP_TAG_SYNC_COOKIE            0x04U
#define sys_LDAP_TAG_REFRESHDELETES         0x01U
#define sys_LDAP_TAG_REFRESHDONE            0x01U
#define sys_LDAP_TAG_RELOAD_HINT            0x01U

#define sys_LDAP_SYNC_PRESENT               0
#define sys_LDAP_SYNC_ADD                   1
#define sys_LDAP_SYNC_MODIFY                2
#define sys_LDAP_SYNC_DELETE                3
#define sys_LDAP_SYNC_NEW_COOKIE            4
/** @} */

/**
 * @name LDAP Don't Use Copy Control (RFC 6171)
 * @{
 */
#define sys_LDAP_CONTROL_DONTUSECOPY        "1.3.6.1.1.22"
/** @} */

/**
 * @name Various works in progress
 * @{
 */
/* Password policy Controls *//* work in progress */
/* ITS#3458: released; disabled by default */
#define sys_LDAP_CONTROL_PASSWORDPOLICYREQUEST    "1.3.6.1.4.1.42.2.27.8.5.1"
#define sys_LDAP_CONTROL_PASSWORDPOLICYRESPONSE   "1.3.6.1.4.1.42.2.27.8.5.1"

/* various works in progress */
#define sys_LDAP_CONTROL_NOOP               "1.3.6.1.4.1.4203.666.5.2"
#define sys_LDAP_CONTROL_NO_SUBORDINATES    "1.3.6.1.4.1.4203.666.5.11"
#define sys_LDAP_CONTROL_RELAX              "1.3.6.1.4.1.4203.666.5.12"
#define sys_LDAP_CONTROL_MANAGEDIT          sys_LDAP_CONTROL_RELAX
#define sys_LDAP_CONTROL_SLURP              "1.3.6.1.4.1.4203.666.5.13"
#define sys_LDAP_CONTROL_VALSORT            "1.3.6.1.4.1.4203.666.5.14"
#define sys_LDAP_CONTROL_X_DEREF            "1.3.6.1.4.1.4203.666.5.16"
#define sys_LDAP_CONTROL_X_WHATFAILED       "1.3.6.1.4.1.4203.666.5.17"

/* LDAP Chaining Behavior Control *//* work in progress */
/* <draft-sermersheim-ldap-chaining>;
 * see also sys_LDAP_NO_REFERRALS_FOUND, sys_LDAP_CANNOT_CHAIN */
#define sys_LDAP_CONTROL_X_CHAINING_BEHAVIOR    "1.3.6.1.4.1.4203.666.11.3"

#define sys_LDAP_CHAINING_PREFERRED               0
#define sys_LDAP_CHAINING_REQUIRED                1
#define sys_LDAP_REFERRALS_PREFERRED              2
#define sys_LDAP_REFERRALS_REQUIRED               3
/** @} */

/**
 * @name MS Active Directory controls (for compatibility)
 * @{
 */
#define sys_LDAP_CONTROL_X_INCREMENTAL_VALUES   "1.2.840.113556.1.4.802"
#define sys_LDAP_CONTROL_X_DOMAIN_SCOPE         "1.2.840.113556.1.4.1339"
#define sys_LDAP_CONTROL_X_PERMISSIVE_MODIFY    "1.2.840.113556.1.4.1413"
#define sys_LDAP_CONTROL_X_SEARCH_OPTIONS       "1.2.840.113556.1.4.1340"
#define sys_LDAP_SEARCH_FLAG_DOMAIN_SCOPE        1    /**< do not generate referrals */
#define sys_LDAP_SEARCH_FLAG_PHANTOM_ROOT        2    /**< search all subordinate NCs */
#define sys_LDAP_CONTROL_X_TREE_DELETE           "1.2.840.113556.1.4.805"
/** @} */

/**
 * @name MS Active Directory controls - not implemented in slapd(8)
 * @{
 */
#define sys_LDAP_CONTROL_X_EXTENDED_DN           "1.2.840.113556.1.4.529"
/** @} */


/**
 * @name <draft-wahl-ldap-session>
 * @{
 */
#define sys_LDAP_CONTROL_X_SESSION_TRACKING      "1.3.6.1.4.1.21008.108.63.1"
#define sys_LDAP_CONTROL_X_SESSION_TRACKING_RADIUS_ACCT_SESSION_ID \
                        sys_LDAP_CONTROL_X_SESSION_TRACKING ".1"
#define sys_LDAP_CONTROL_X_SESSION_TRACKING_RADIUS_ACCT_MULTI_SESSION_ID \
                        sys_LDAP_CONTROL_X_SESSION_TRACKING ".2"
#define sys_LDAP_CONTROL_X_SESSION_TRACKING_USERNAME \
                        sys_LDAP_CONTROL_X_SESSION_TRACKING ".3"
/** @} */

/* various expired works */

/**
 * @name LDAP Duplicated Entry Control Extension *//* not implemented in slapd(8)
 * @{
 */
#define sys_LDAP_CONTROL_DUPENT_REQUEST        "2.16.840.1.113719.1.27.101.1"
#define sys_LDAP_CONTROL_DUPENT_RESPONSE       "2.16.840.1.113719.1.27.101.2"
#define sys_LDAP_CONTROL_DUPENT_ENTRY          "2.16.840.1.113719.1.27.101.3"
#define sys_LDAP_CONTROL_DUPENT                sys_LDAP_CONTROL_DUPENT_REQUEST
/** @} */

/**
 * @name LDAP Persistent Search Control *//* not implemented in slapd(8)
 * @{
 */
#define sys_LDAP_CONTROL_PERSIST_REQUEST                "2.16.840.1.113730.3.4.3"
#define sys_LDAP_CONTROL_PERSIST_ENTRY_CHANGE_NOTICE    "2.16.840.1.113730.3.4.7"
#define sys_LDAP_CONTROL_PERSIST_ENTRY_CHANGE_ADD       0x1
#define sys_LDAP_CONTROL_PERSIST_ENTRY_CHANGE_DELETE    0x2
#define sys_LDAP_CONTROL_PERSIST_ENTRY_CHANGE_MODIFY    0x4
#define sys_LDAP_CONTROL_PERSIST_ENTRY_CHANGE_RENAME    0x8
/** @} */

/**
 * @name LDAP VLV
 * @{
 */
#define sys_LDAP_CONTROL_VLVREQUEST        "2.16.840.1.113730.3.4.9"
#define sys_LDAP_CONTROL_VLVRESPONSE       "2.16.840.1.113730.3.4.10"
/** @} */

/**
 * @name LDAP Unsolicited Notifications
 * @{
 */
#define sys_LDAP_NOTICE_OF_DISCONNECTION    "1.3.6.1.4.1.1466.20036" /**< RFC 4511 */
#define sys_LDAP_NOTICE_DISCONNECT          sys_LDAP_NOTICE_OF_DISCONNECTION
/** @} */

/**
 * @name LDAP Extended Operations
 * @{
 */
#define sys_LDAP_EXOP_START_TLS        "1.3.6.1.4.1.1466.20037"    /**< RFC 4511 */

#define sys_LDAP_EXOP_MODIFY_PASSWD           "1.3.6.1.4.1.4203.1.11.1"    /**< RFC 3062 */
#define sys_LDAP_TAG_EXOP_MODIFY_PASSWD_ID    0x80U
#define sys_LDAP_TAG_EXOP_MODIFY_PASSWD_OLD   0x81U
#define sys_LDAP_TAG_EXOP_MODIFY_PASSWD_NEW   0x82U
#define sys_LDAP_TAG_EXOP_MODIFY_PASSWD_GEN   0x80U

#define sys_LDAP_EXOP_CANCEL        "1.3.6.1.1.8"                    /**< RFC 3909 */
#define sys_LDAP_EXOP_X_CANCEL      sys_LDAP_EXOP_CANCEL

#define sys_LDAP_EXOP_REFRESH               "1.3.6.1.4.1.1466.101.119.1"    /**< RFC 2589 */
#define sys_LDAP_TAG_EXOP_REFRESH_REQ_DN    0x80U
#define sys_LDAP_TAG_EXOP_REFRESH_REQ_TTL   0x81U
#define sys_LDAP_TAG_EXOP_REFRESH_RES_TTL   0x81U

#define sys_LDAP_EXOP_WHO_AM_I        "1.3.6.1.4.1.4203.1.11.3"        /**< RFC 4532 */
#define sys_LDAP_EXOP_X_WHO_AM_I      sys_LDAP_EXOP_WHO_AM_I

/* various works in progress */
#define sys_LDAP_EXOP_TURN        "1.3.6.1.1.19"                /**< RFC 4531 */
#define sys_LDAP_EXOP_X_TURN      sys_LDAP_EXOP_TURN
/** @} */

/**
 * @name LDAP Distributed Procedures <draft-sermersheim-ldap-distproc>
 * @{
 */
/* a work in progress */
#define sys_LDAP_X_DISTPROC_BASE          "1.3.6.1.4.1.4203.666.11.6"
#define sys_LDAP_EXOP_X_CHAINEDREQUEST    sys_LDAP_X_DISTPROC_BASE ".1"
#define sys_LDAP_FEATURE_X_CANCHAINOPS    sys_LDAP_X_DISTPROC_BASE ".2"
#define sys_LDAP_CONTROL_X_RETURNCONTREF  sys_LDAP_X_DISTPROC_BASE ".3"
#define sys_LDAP_URLEXT_X_LOCALREFOID     sys_LDAP_X_DISTPROC_BASE ".4"
#define sys_LDAP_URLEXT_X_REFTYPEOID      sys_LDAP_X_DISTPROC_BASE ".5"
#define sys_LDAP_URLEXT_X_SEARCHEDSUBTREEOID \
                    sys_LDAP_X_DISTPROC_BASE ".6"
#define sys_LDAP_URLEXT_X_FAILEDNAMEOID    sys_LDAP_X_DISTPROC_BASE ".7"
#define sys_LDAP_URLEXT_X_LOCALREF         "x-localReference"
#define sys_LDAP_URLEXT_X_REFTYPE          "x-referenceType"
#define sys_LDAP_URLEXT_X_SEARCHEDSUBTREE  "x-searchedSubtree"
#define sys_LDAP_URLEXT_X_FAILEDNAME       "x-failedName"
/** @} */

/**
 * @name LDAP Features
 * @{
 */
#define sys_LDAP_FEATURE_ALL_OP_ATTRS    "1.3.6.1.4.1.4203.1.5.1"    /**< RFC 3673 */
#define sys_LDAP_FEATURE_OBJECTCLASS_ATTRS \
    "1.3.6.1.4.1.4203.1.5.2" /*  @objectClass - new number to be assigned */
#define sys_LDAP_FEATURE_ABSOLUTE_FILTERS        "1.3.6.1.4.1.4203.1.5.3"  /* (&) (|) */
#define sys_LDAP_FEATURE_LANGUAGE_TAG_OPTIONS    "1.3.6.1.4.1.4203.1.5.4"
#define sys_LDAP_FEATURE_LANGUAGE_RANGE_OPTIONS  "1.3.6.1.4.1.4203.1.5.5"
#define sys_LDAP_FEATURE_MODIFY_INCREMENT        "1.3.6.1.1.14"
/** @} */

/**
 * @name General stuff
 * @{
 */
#define sys_LDAP_TAG_MESSAGE      0x30U    /**< constructed + 16 */
#define sys_LDAP_TAG_MSGID        0x02U    /**< integer */

#define sys_LDAP_TAG_LDAPDN       0x04U    /**< octet string */
#define sys_LDAP_TAG_LDAPCRED     0x04U    /**< octet string */

#define sys_LDAP_TAG_CONTROLS     0xa0U    /**< context specific + constructed + 0 */
#define sys_LDAP_TAG_REFERRAL     0xa3U    /**< context specific + constructed + 3 */

#define sys_LDAP_TAG_NEWSUPERIOR  0x80U    /**< context-specific + primitive + 0 */

#define sys_LDAP_TAG_EXOP_REQ_OID    0x80U    /**< context specific + primitive */
#define sys_LDAP_TAG_EXOP_REQ_VALUE  0x81U    /**< context specific + primitive */
#define sys_LDAP_TAG_EXOP_RES_OID    0x8aU    /**< context specific + primitive */
#define sys_LDAP_TAG_EXOP_RES_VALUE  0x8bU    /**< context specific + primitive */

#define sys_LDAP_TAG_IM_RES_OID     0x80U    /**< context specific + primitive */
#define sys_LDAP_TAG_IM_RES_VALUE   0x81U    /**< context specific + primitive */

#define sys_LDAP_TAG_SASL_RES_CREDS  0x87U    /**< context specific + primitive */
/** @} */

/**
 * @name LDAP Request Messages
 * @{
 */
#define sys_LDAP_REQ_BIND        0x60U    /**< application + constructed */
#define sys_LDAP_REQ_UNBIND      0x42U    /**< application + primitive   */
#define sys_LDAP_REQ_SEARCH      0x63U    /**< application + constructed */
#define sys_LDAP_REQ_MODIFY      0x66U    /**< application + constructed */
#define sys_LDAP_REQ_ADD         0x68U    /**< application + constructed */
#define sys_LDAP_REQ_DELETE      0x4aU    /**< application + primitive   */
#define sys_LDAP_REQ_MODDN       0x6cU    /**< application + constructed */
#define sys_LDAP_REQ_MODRDN      sys_LDAP_REQ_MODDN
#define sys_LDAP_REQ_RENAME      sys_LDAP_REQ_MODDN
#define sys_LDAP_REQ_COMPARE     0x6eU    /**< application + constructed */
#define sys_LDAP_REQ_ABANDON     0x50U    /**< application + primitive   */
#define sys_LDAP_REQ_EXTENDED    0x77U    /**< application + constructed */
/** @} */

/**
 * @name LDAP Response Messages
 * @{
 */
#define sys_LDAP_RES_BIND              0x61U    /**< application + constructed */
#define sys_LDAP_RES_SEARCH_ENTRY      0x64U    /**< application + constructed */
#define sys_LDAP_RES_SEARCH_REFERENCE  0x73U    /**< V3: application + constructed */
#define sys_LDAP_RES_SEARCH_RESULT     0x65U    /**< application + constructed */
#define sys_LDAP_RES_MODIFY            0x67U    /**< application + constructed */
#define sys_LDAP_RES_ADD               0x69U    /**< application + constructed */
#define sys_LDAP_RES_DELETE            0x6bU    /**< application + constructed */
#define sys_LDAP_RES_MODDN             0x6dU    /**< application + constructed */
#define sys_LDAP_RES_MODRDN            sys_LDAP_RES_MODDN     /**< application + constructed */
#define sys_LDAP_RES_RENAME            sys_LDAP_RES_MODDN     /**< application + constructed */
#define sys_LDAP_RES_COMPARE           0x6fU    /**< application + constructed */
#define sys_LDAP_RES_EXTENDED          0x78U    /**< V3: application + constructed */
#define sys_LDAP_RES_INTERMEDIATE      0x79U    /**< V3+: application + constructed */

#define sys_LDAP_RES_ANY            (-1)
#define sys_LDAP_RES_UNSOLICITED    (0)
/** @} */

/**
 * @name SASL methods
 * @{
 */
#define sys_LDAP_SASL_SIMPLE    ((char*)0)
#define sys_LDAP_SASL_NULL        ("")
/** @} */


/**
 * @name Authentication methods available
 * @{
 */
#define sys_LDAP_AUTH_NONE   0x00U  /**< no authentication */
#define sys_LDAP_AUTH_SIMPLE 0x80U  /**< context specific + primitive */
#define sys_LDAP_AUTH_SASL   0xa3U  /**< context specific + constructed */
#define sys_LDAP_AUTH_KRBV4  0xffU  /**< means do both of the following */
#define sys_LDAP_AUTH_KRBV41 0x81U  /**< context specific + primitive */
#define sys_LDAP_AUTH_KRBV42 0x82U  /**< context specific + primitive */
/** @} */

/**
 * @name Filter types
 * @{
 */
#define sys_LDAP_FILTER_AND          0xa0U   /**< context specific + constructed */
#define sys_LDAP_FILTER_OR           0xa1U   /**< context specific + constructed */
#define sys_LDAP_FILTER_NOT          0xa2U   /**< context specific + constructed */
#define sys_LDAP_FILTER_EQUALITY     0xa3U   /**< context specific + constructed */
#define sys_LDAP_FILTER_SUBSTRINGS   0xa4U   /**< context specific + constructed */
#define sys_LDAP_FILTER_GE           0xa5U   /**< context specific + constructed */
#define sys_LDAP_FILTER_LE           0xa6U   /**< context specific + constructed */
#define sys_LDAP_FILTER_PRESENT      0x87U   /**< context specific + primitive   */
#define sys_LDAP_FILTER_APPROX       0xa8U   /**< context specific + constructed */
#define sys_LDAP_FILTER_EXT          0xa9U   /**< context specific + constructed */
/** @} */

/**
 * @name Extended filter component types
 * @{
 */
#define sys_LDAP_FILTER_EXT_OID      0x81U    /**< context specific */
#define sys_LDAP_FILTER_EXT_TYPE     0x82U    /**< context specific */
#define sys_LDAP_FILTER_EXT_VALUE    0x83U    /**< context specific */
#define sys_LDAP_FILTER_EXT_DNATTRS  0x84U    /**< context specific */
/** @} */

/**
 * @name Substring filter component types
 * @{
 */
#define sys_LDAP_SUBSTRING_INITIAL    0x80U    /**< context specific */
#define sys_LDAP_SUBSTRING_ANY        0x81U    /**< context specific */
#define sys_LDAP_SUBSTRING_FINAL      0x82U    /**< context specific */
/** @} */

/**
 * @name Search scopes
 * @{
 */
#define sys_LDAP_SCOPE_BASE            0x0000
#define sys_LDAP_SCOPE_BASEOBJECT      sys_LDAP_SCOPE_BASE
#define sys_LDAP_SCOPE_ONELEVEL        0x0001
#define sys_LDAP_SCOPE_ONE             sys_LDAP_SCOPE_ONELEVEL
#define sys_LDAP_SCOPE_SUBTREE         0x0002
#define sys_LDAP_SCOPE_SUB             sys_LDAP_SCOPE_SUBTREE
#define sys_LDAP_SCOPE_SUBORDINATE     0x0003 /**< OpenLDAP extension */
#define sys_LDAP_SCOPE_CHILDREN        sys_LDAP_SCOPE_SUBORDINATE
#define sys_LDAP_SCOPE_DEFAULT         (-1)     /**< OpenLDAP extension */
/** @} */

/**
 * @name Substring filter component types
 * @{
 */
#define sys_LDAP_SUBSTRING_INITIAL    0x80U    /**< context specific */
#define sys_LDAP_SUBSTRING_ANY        0x81U    /**< context specific */
#define sys_LDAP_SUBSTRING_FINAL      0x82U    /**< context specific */
/** @} */


/**
 * @name LDAP Result Codes
 * @{
 */
#define sys_LDAP_SUCCESS                0x00  /*< success **/

#define sys_LDAP_RANGE(n,x,y)    (((x) <= (n)) && ((n) <= (y)))

#define sys_LDAP_OPERATIONS_ERROR           0x01
#define sys_LDAP_PROTOCOL_ERROR             0x02
#define sys_LDAP_TIMELIMIT_EXCEEDED         0x03
#define sys_LDAP_SIZELIMIT_EXCEEDED         0x04
#define sys_LDAP_COMPARE_FALSE              0x05
#define sys_LDAP_COMPARE_TRUE               0x06
#define sys_LDAP_AUTH_METHOD_NOT_SUPPORTED  0x07
#define sys_LDAP_STRONG_AUTH_NOT_SUPPORTED  sys_LDAP_AUTH_METHOD_NOT_SUPPORTED
#define sys_LDAP_STRONG_AUTH_REQUIRED       0x08
#define sys_LDAP_STRONGER_AUTH_REQUIRED     sys_LDAP_STRONG_AUTH_REQUIRED

#define sys_LDAP_REFERRAL                         0x0a /**< LDAPv3 */
#define sys_LDAP_ADMINLIMIT_EXCEEDED              0x0b /**< LDAPv3 */
#define sys_LDAP_UNAVAILABLE_CRITICAL_EXTENSION   0x0c /**< LDAPv3 */
#define sys_LDAP_CONFIDENTIALITY_REQUIRED         0x0d /**< LDAPv3 */
#define sys_LDAP_SASL_BIND_IN_PROGRESS            0x0e /**< LDAPv3 */

#define sys_LDAP_ATTR_ERROR(n)    sys_LDAP_RANGE((n),0x10,0x15) /* 16-21 */

#define sys_LDAP_NO_SUCH_ATTRIBUTE         0x10
#define sys_LDAP_UNDEFINED_TYPE            0x11
#define sys_LDAP_INAPPROPRIATE_MATCHING    0x12
#define sys_LDAP_CONSTRAINT_VIOLATION      0x13
#define sys_LDAP_TYPE_OR_VALUE_EXISTS      0x14
#define sys_LDAP_INVALID_SYNTAX            0x15

#define sys_LDAP_NAME_ERROR(n)    sys_LDAP_RANGE((n),0x20,0x24) /**< 32-34,36 */

#define sys_LDAP_NO_SUCH_OBJECT           0x20
#define sys_LDAP_ALIAS_PROBLEM            0x21
#define sys_LDAP_INVALID_DN_SYNTAX        0x22
#define sys_LDAP_IS_LEAF                  0x23 /**< not LDAPv3 */
#define sys_LDAP_ALIAS_DEREF_PROBLEM      0x24

#define sys_LDAP_SECURITY_ERROR(n)    sys_LDAP_RANGE((n),0x2F,0x32) /**< 47-50 */

#define sys_LDAP_X_PROXY_AUTHZ_FAILURE     0x2F /**< LDAPv3 proxy authorization */
#define sys_LDAP_INAPPROPRIATE_AUTH        0x30
#define sys_LDAP_INVALID_CREDENTIALS       0x31
#define sys_LDAP_INSUFFICIENT_ACCESS       0x32

#define sys_LDAP_SERVICE_ERROR(n)    sys_LDAP_RANGE((n),0x33,0x36) /**< 51-54 */

#define sys_LDAP_BUSY                   0x33
#define sys_LDAP_UNAVAILABLE            0x34
#define sys_LDAP_UNWILLING_TO_PERFORM   0x35
#define sys_LDAP_LOOP_DETECT            0x36

#define sys_LDAP_UPDATE_ERROR(n)    sys_LDAP_RANGE((n),0x40,0x47) /**< 64-69,71 */

#define sys_LDAP_NAMING_VIOLATION          0x40
#define sys_LDAP_OBJECT_CLASS_VIOLATION    0x41
#define sys_LDAP_NOT_ALLOWED_ON_NONLEAF    0x42
#define sys_LDAP_NOT_ALLOWED_ON_RDN        0x43
#define sys_LDAP_ALREADY_EXISTS            0x44
#define sys_LDAP_NO_OBJECT_CLASS_MODS      0x45
#define sys_LDAP_RESULTS_TOO_LARGE         0x46 /**< CLDAP */
#define sys_LDAP_AFFECTS_MULTIPLE_DSAS     0x47

#define sys_LDAP_VLV_ERROR                0x4C

#define sys_LDAP_OTHER                    0x50

/* LCUP operation codes (113-117) - not implemented */
#define sys_LDAP_CUP_RESOURCES_EXHAUSTED    0x71
#define sys_LDAP_CUP_SECURITY_VIOLATION     0x72
#define sys_LDAP_CUP_INVALID_DATA           0x73
#define sys_LDAP_CUP_UNSUPPORTED_SCHEME     0x74
#define sys_LDAP_CUP_RELOAD_REQUIRED        0x75

/* Cancel operation codes (118-121) */
#define sys_LDAP_CANCELLED                0x76
#define sys_LDAP_NO_SUCH_OPERATION        0x77
#define sys_LDAP_TOO_LATE                 0x78
#define sys_LDAP_CANNOT_CANCEL            0x79

/* Assertion control (122) */ 
#define sys_LDAP_ASSERTION_FAILED        0x7A

/* Proxied Authorization Denied (123) */ 
#define sys_LDAP_PROXIED_AUTHORIZATION_DENIED        0x7B

/* Experimental result codes */
#define sys_LDAP_E_ERROR(n)    sys_LDAP_RANGE((n),0x1000,0x3FFF)

/* LDAP Sync (4096) */
#define sys_LDAP_SYNC_REFRESH_REQUIRED        0x1000


/* Private Use result codes */
#define sys_LDAP_X_ERROR(n)    sys_LDAP_RANGE((n),0x4000,0xFFFF)

#define sys_LDAP_X_SYNC_REFRESH_REQUIRED    0x4100 /**< defunct */
#define LDAP_X_ASSERTION_FAILED             0x410f /**< defunct */

/* for the LDAP No-Op control */
#define sys_LDAP_X_NO_OPERATION             0x410e
/** @} */

/**
 * @name API Error Codes
 * Based on draft-ietf-ldap-c-api-xx
 * but with new negative code values
 * @{
 */
#define sys_LDAP_API_ERROR(n)          ((n)<0)
#define sys_LDAP_API_RESULT(n)         ((n)<=0)

#define sys_LDAP_SERVER_DOWN                (-1)
#define sys_LDAP_LOCAL_ERROR                (-2)
#define sys_LDAP_ENCODING_ERROR             (-3)
#define sys_LDAP_DECODING_ERROR             (-4)
#define sys_LDAP_TIMEOUT                    (-5)
#define sys_LDAP_AUTH_UNKNOWN               (-6)
#define sys_LDAP_FILTER_ERROR               (-7)
#define sys_LDAP_USER_CANCELLED             (-8)
#define sys_LDAP_PARAM_ERROR                (-9)
#define sys_LDAP_NO_MEMORY                  (-10)
#define sys_LDAP_CONNECT_ERROR              (-11)
#define sys_LDAP_NOT_SUPPORTED              (-12)
#define sys_LDAP_CONTROL_NOT_FOUND          (-13)
#define sys_LDAP_NO_RESULTS_RETURNED        (-14)
#define sys_LDAP_MORE_RESULTS_TO_RETURN     (-15)    /**< Obsolete */
#define sys_LDAP_CLIENT_LOOP                (-16)
#define sys_LDAP_REFERRAL_LIMIT_EXCEEDED    (-17)
#define    sys_LDAP_X_CONNECTING            (-18)
/** @} */

/**
 * This structure represents both ldap messages and ldap responses.
 * These are really the same, except in the case of search responses,
 * where a response has multiple messages.
 */
typedef struct sys_ldapmsg sys_LDAPMessage;

/**
 *  for modifications
 */
typedef struct sys_ldapmod {
    SINT        mod_op;      /**< specifies the type of modification to perform */

#define sys_LDAP_MOD_OP         (0x0007)
#define sys_LDAP_MOD_ADD        (0x0000)
#define sys_LDAP_MOD_DELETE     (0x0001)
#define sys_LDAP_MOD_REPLACE    (0x0002)
#define sys_LDAP_MOD_INCREMENT  (0x0003) /**< OpenLDAP extension */
#define sys_LDAP_MOD_BVALUES    (0x0080)
/* IMPORTANT: do not use code 0x1000 (or above),
 * it is used internally by the backends!
 */

    char        *sys_mod_type;    /**< specifies the attribute type to modify */
    union sys_mod_vals_u {
        char        **modv_strvals;
        struct sys_berval    **modv_bvals;
    } mod_vals;                  /**< null-terminated array of values to add, delete, or replace respectively */
#define sys_mod_values    sys_mod_vals.sys_modv_strvals
#define sys_mod_bvalues    sys_mod_vals.sys_modv_bvals
} sys_LDAPMod;

/**
 * structure representing an ldap session which can
 * encompass connections to multiple servers (in the
 * face of referrals).
 */
typedef struct sys_ldap sys_LDAP;

/**
 * @name Defines for referrals.
 * @{
 */
#define sys_LDAP_DEREF_NEVER        0x00
#define sys_LDAP_DEREF_SEARCHING    0x01
#define sys_LDAP_DEREF_FINDING      0x02
#define sys_LDAP_DEREF_ALWAYS       0x03
/** @} */

#define sys_LDAP_NO_LIMIT           0 /**< No limit*/

/**
 * @name How many messages to retrieve results for
 * @{
 */
#define sys_LDAP_MSG_ONE            0x00
#define sys_LDAP_MSG_ALL            0x01
#define sys_LDAP_MSG_RECEIVED       0x02
/** @} */

/**
 * Types for ldap URL handling
 */
typedef struct sys_ldap_url_desc {
    struct sys_ldap_url_desc *lud_next; /**< struct for URL handling */
    char    *lud_scheme;      /**< URI scheme */
    char    *lud_host;        /**< LDAP host to contact */
    SINT     lud_port;        /**< port on host */
    char    *lud_dn;          /**< base for search */
    char    **lud_attrs;      /**< list of attributes */
    SINT     lud_scope;       /**< a sys_LDAP_SCOPE_... value */
    char    *lud_filter;      /**< LDAP search filter */
    char    **lud_exts;       /**< LDAP extensions */
    SINT     lud_crit_exts;   /**< true if any extension is critical */
} sys_LDAPURLDesc;

/**
 * @name Defines for ldap URL handling
 * @{
 */
#define sys_LDAP_URL_SUCCESS           0x00    /**< Success */
#define sys_LDAP_URL_ERR_MEM           0x01    /**< can't allocate memory space */
#define sys_LDAP_URL_ERR_PARAM         0x02    /**< parameter is bad */

#define sys_LDAP_URL_ERR_BADSCHEME     0x03    /**< URL doesn't begin with "ldap[si]://" */
#define sys_LDAP_URL_ERR_BADENCLOSURE  0x04    /**< URL is missing trailing ">" */
#define sys_LDAP_URL_ERR_BADURL        0x05    /**< URL is bad */
#define sys_LDAP_URL_ERR_BADHOST       0x06    /**< host port is bad */
#define sys_LDAP_URL_ERR_BADATTRS      0x07    /**< bad (or missing) attributes */
#define sys_LDAP_URL_ERR_BADSCOPE      0x08    /**< scope string is invalid (or missing) */
#define sys_LDAP_URL_ERR_BADFILTER     0x09    /**< bad or missing filter */
#define sys_LDAP_URL_ERR_BADEXTS       0x0a    /**< bad or missing extensions */
/** @} */
/** @} end of SYS-LDAP-DEF */


/**
 * @addtogroup SYS-LDAP-API
 * @{
 */

/**
* @brief Initialize the LDAP library and open a connection to an LDAP server
*
* @param[in,out]   ld     LDAP handle.
*                         Structure which is used to identify the connection and to 
*                         maintain connection information.
* @param[out]      uri    The uri containins  only the schema, the host, and the port fields.
*                         Apart from ldap, other (non-standard) recognized values of the
*                         schema field are ldaps (LDAP over TLS), ldapi (LDAP over IPC),
*                         and cldap (connectionless LDAP).  
*                         If other fields are present, the behavior is undefined.
*
* @returns an integer indicating either success (sys_LDAP_SUCCESS) or the failure reason.
*/
SINT sys_ldap_Initialize(sys_LDAP **ld, char *uri);

/**
* @brief This function provides access to options stored either in a LDAP handle
*        or as global options, where applicable.
*
* Global options are retrieved by passing a NULL LDAP handle.
* LDAP handles  inherit their  default settings from the global options in
* effect at the time the handle is created.
*
* @see @ref sys_LDAP_OPT_
*
* @param[in]        ld             LDAP handle.
* @param[in]        optionToGet    The actual type is determined based on the value of the option argument (@ref sys_LDAP_OPT_).
* @param[out]       optionValue    Value of option specified by `optionToGet`.
*
* @returns an integer indicating either success (sys_LDAP_SUCCESS) or the failure reason.
*/
SINT sys_ldap_GetOption(sys_LDAP *ld, SINT optionToGet, void *optionValue);

/**
* @brief This function provides access to options stored either in a LDAP handle
*        or as global options, where applicable.
*
* Global options are set by passing a NULL LDAP handle.
* LDAP handles  inherit their  default settings from the global options in
* effect at the time the handle is created.
*
* @see @ref sys_LDAP_OPT_
*
* @param[in]        ld             LDAP handle.
* @param[in]        optionToSet    The actual type is determined based on the value of the option argument (@ref sys_LDAP_OPT_).
* @param[in]        optionValue    Value to set foroption specified by `optionToGet`.
*
* @returns an integer indicating either success (sys_LDAP_SUCCESS) or the failure reason.
*/
SINT sys_ldap_SetOption(sys_LDAP *ld, SINT optionToSet, const void *optionValue);

/**
* @brief  This function provides an interface to the LDAP bind operation via simple authentication.
*
* After an association with an LDAP server is made using sys_ldap_initialize(),
* an LDAP bind operation should be performed before other operations are
* attempted over the connection. An LDAP bind is required when using
* Version 2 of the LDAP protocol; it is optional for Version 3 but is
* usually needed due to security considerations.
*
* @param[in]        ld             LDAP handle.
* @param[in]        dn             The Distinguished Name of the entry to bind as, may be NULL.
* @param[in]        passwd         User password.
*
* @returns an integer indicating either success (sys_LDAP_SUCCESS) or the failure reason.
*/
SINT sys_ldap_SimpleBindS(sys_LDAP *ld, const char *dn, const char *passwd);

/**
* @brief  This function provides an interface to the LDAP bind operation via SASL authentication.
*
* After an association with an LDAP server is made using sys_ldap_initialize(),
* an LDAP bind operation should be performed before other operations are
* attempted over the connection. An LDAP bind is required when using
* Version 2 of the LDAP protocol; it is optional for Version 3 but is
* usually needed due to security considerations.
*
* For SASL binds the server always ignores any provided DN, so the dn
* parameter should always be NULL. sys_ldap_SaslBindS() sends a single
* SASL bind request with the given SASL mechanism and credentials in the
* cred parameter. The format of the credentials depends on the particular
* SASL mechanism in use. For mechanisms that provide mutual
* authentication the server's credentials will be returned in the
* `servercredp` parameter.  The routine returns an LDAP error indication
* (see ldap_error(3)).
*
* SASL (Simple Authentication and Security Layer) can negotiate one of
* many different kinds of authentication.
*
* @param[in]        ld             LDAP handle.
* @param[in]        dn             The Distinguished Name of the entry to bind as, may be NULL.
* @param[in]        mechanism      SASL mechanism.
* @param[in]        cred           Credentials.
* @param[in]        serverctrls    Specifies a list of LDAP server controls. This parameter may be set to NULL.
* @param[in]        clientctrls    Specifies a list of LDAP client controls. This parameter may be set to NULL.
* @param[out]       servercredp    This result parameter will be set to the credentials returned by the server. 
*                                  If no credentials are returned, it will be set to NULL.
*
* @returns an integer indicating either success (sys_LDAP_SUCCESS) or the failure reason.
*/
SINT sys_ldap_SaslBindS(sys_LDAP *ld, const char *dn, const char *mechanism, 
                        const struct sys_berval *cred, sys_LDAPControl **serverctrls,
                        sys_LDAPControl **clientctrls, struct sys_berval **servercredp);

/**
* @brief  This function  initiates a synchronous search operation, 
*         allowing LDAP controls to be sent to the server and client.
*
* @param[in]        ld             LDAP handle.
* @param[in]        base           Specifies the DN of the entry at which to start the search.
* @param[in]        scope          Specifies the scope of the search. 
*                                  It can be sys_LDAP_SCOPE_BASE (to search the object itself), 
*                                  or sys_LDAP_SCOPE_ONELEVEL (to search the object's immediate children), 
*                                  or sys_LDAP_SCOPE_SUBTREE (to search the object and all its descendents).
* @param[in]        filter         Specifies a string representation of the filter to apply in the search.
* @param[in]        attr           Specifies a null-terminated array of character string attribute types 
*                                  to return from entries that match filter. 
*                                  If NULL is specified, all attributes will be returned.
* @param[in]        attrsonly      Specifies attribute information. Attrsonly should be set to 1 to request attribute types only.
*                                  Set to 0 to request both attributes types and attribute values.
* @param[in]        serverctrls    Specifies a list of LDAP server controls. This parameter may be set to null. 
* @param[in]        clientctrls    Specifies a list of LDAP client controls. This parameter may be set to null.
* @param[in]        timeout        The local search timeout value and the operation time limit that is sent to the server within the search request.
* @param[in]        sizelimit      Specifies the maximum number of entries to return. 
*                                  Note that the server may set a lower limit which is enforced at the server.
* @param[out]       res            Contains the result of the synchronous search operation. 
*                                  This result should be passed to the LDAP parsing routines (sys_ldap_FirstEntry(), sys_ldap_NextEntry(), ...). 
*                                  The caller is responsible for freeing res with sys_ldap_Msgfree().
*
* @returns an integer indicating either success (sys_LDAP_SUCCESS) or the failure reason.
*/
SINT sys_ldap_SearchExtS(sys_LDAP *ld, const char *base, SINT scope, 
                         const char *filter, char **attr, SINT attrsonly,
                         sys_LDAPControl **serverctrls, sys_LDAPControl **clientctrls,
                         struct timeval *timeout, SINT sizelimit, 
                         sys_LDAPMessage **res);

/**
* @brief  This function takes the result from a call to an LDAP search (for example sys_ldap_SearchExtS())
*         and returns a pointer to the first entry in the result.
*
* @param[in]        ld             LDAP handle.
* @param[in]        chain          The result returned by a call to one of the synchronous search routines.
*
* @returns a pointer to the first entry in the result if the request was successful or NULL if the request was not successful. 
*/
sys_LDAPMessage *sys_ldap_FirstEntry(sys_LDAP *ld, sys_LDAPMessage *chain);

/**
* @brief  This function takes the result from a call to an LDAP search (for example sys_ldap_search_s()) 
*         and returns a pointer to the next entry in a chain of results.
*
* @param[in]        ld             LDAP handle.
* @param[in]        entry          Specifies a pointer to an entry returned on a previous call to 
*                                  sys_ldap_FirstEntry() or sys_ldap_NextEntry().
*
* @returns a pointer to the next entry in the result if the request was successful or NULL if the request was not successful. 
*/
sys_LDAPMessage *sys_ldap_NextEntry(sys_LDAP *ld, sys_LDAPMessage *entry);

/**
* @brief  This function returns the number of entries contained in a search result chain.
*
* It can also be used to count the number of entries that remain in a chain if called with a message,
* entry or continuation reference returned by sys_ldap_FirstEntry() or sys_ldap_NextEntry(), etc. respectively.
*
* @param[in]        ld             LDAP handle.
* @param[in]        chain          The result returned by a call to one of synchronous search routines.
*
* @returns The number of entries contained in a search result chain if successful or (-1) if the request was not successful.
*/
SINT sys_ldap_CountEntries(sys_LDAP *ld, sys_LDAPMessage *chain);

/**
* @brief  This function takes an entry as returned by sys_ldap_FirstEntry() or sys_ldap_NextEntry()
*         and returns a copy of the entry's Distinguished Name (DN).
*
* Memory for the DN will have been allocated and should be freed by a call to sys_ldap_Memfree().
*
* @param[in]        ld             LDAP handle.
* @param[in]        entry          The entry whose dn is to be retrieved, as returned by Specifies the LDAP 
*                                  pointer returned by a previous call to sys_ldap_FirstEntry() or sys_ldap_NextEntry().
*
* @returns Copy of the entry's DN if successful or NULL if the request was not successful.
*/
char *sys_ldap_GetDn(sys_LDAP *ld, sys_LDAPMessage *entry);

/**
* @brief  This function is used to perform a synchronous LDAP compare operation with controls.
*
* @param[in]        ld             LDAP handle.
* @param[in]        dn             The distinguished name (DN) of the entry upon which to perform the compare.
* @param[in]        attr           The attribute type to use in the comparison.
* @param[in]        bvalue         The attribute value to compare against the value in the entry. 
*                                  This is a pointer to a struct sys_berval, making it possible to compare binary values.
* @param[in]        serverctrls    A list of LDAP server controls. This parameter may be set to null.
* @param[in]        clientctrls    A list of LDAP client controls. This parameter may be set to null.
*
* @retval sys_LDAP_COMPARE_TRUE if the entry contains the attribute value.
* @retval sys_LDAP_COMPARE_FALSE if the entry does not contain the attribute value.
* @retval other if the request was not successful.
*/
SINT sys_ldap_CompareExtS(sys_LDAP *ld, const char *dn, const char *attr,
                          struct sys_berval *bvalue, sys_LDAPControl **serverctrls,
                          sys_LDAPControl **clientctrls);

/**
* @brief  This function is used to free the memory allocated for an LDAP message by sys_ldap_SearchExtS(), etc. 
*
* It takes a pointer to the result to be freed and returns the type of the message it freed.
*
* @param[in]        msg             Specifies pointer to the memory allocated for an LDAP message.
*
* @returns The type of the message freed if successfull or zero if the input pointer to sys_LDAPMessage structure is NULL..
*/
SINT sys_ldap_Msgfree(sys_LDAPMessage *msg);

/**
* @brief  This function is used to free storage that is allocated by some of the LDAP APIs. 
*
* See the specific LDAP API documentation to see which memory free API to use for any memory allocated.
*
* @param[in]        mem             Specifies the address of storage that was allocated by the LDAP library.
*/
void sys_ldap_Memfree(void *mem);

/**
* @brief  This function is used to end the connection to the LDAP server and free the resources contained in the ld structure.
*
* Once it is called, any open connection to the LDAP server is closed, and the ld structure is invalid.
*
* @param[in]        ld             LDAP handle.
* 
* @returns sys_LDAP_SUCCESS if the request was successful or another LDAP error if the request was not successful.
*/
SINT sys_ldap_UnbindS(sys_LDAP *ld);

/**
* @brief  This function is used to retrieve the text description corresponding to an LDAP error code.
*
* The text description returned will be provided in English only.
* The string returned from sys_ldap_Err2String() should not be freed when use of the string is complete.
*
* @param[in]        err             Specifies the LDAP error code returned by a synchronous LDAP API.
* 
* @returns a textual description of the LDAP error code.
*/
char *sys_ldap_Err2String(SINT err);

/**
* @brief  This function frees a sys_BerElement pointed to by ber.
*
* If ber is NULL, the routine does nothing.  If freebuf is zero, the internal buffer is not freed.
*
* @param[in]        ber             Opaque structure used to maintain state information used in encoding and decoding.
* @param[in]        freebuf         Indicates if the internal buffer is freed or not.
*                                   If freebuf is zero, the internal buffer is not freed. 
*/
void sys_ldap_ber_free(sys_BerElement *ber, SINT freebuf);

/**
* @brief  This function returns the first attribute in an entry. 
*
* The sys_ldap_FirstAttribute() and sys_ldap_NextAttribute() functions are used
* to step through the attributes in an LDAP entry. sys_ldap_FirstAttribute() takes an entry returned
* by sys_ldap_FirstEntry() or sys_ldap_NextEntry() and returns a pointer to a buffer containing
* a null terminated string that is the first attribute type in the entry.
* This buffer must be freed when its use is completed using sys_ldap_Memfree().
* *ber also must be freed when its use is completed using sys_ldap_ber_free().
*
* @param[in]        ld             LDAP handle.
* @param[in]        entry          The attribute information as returned by sys_ldap_FirstEntry() or sys_ldap_NextEntry().
* @param[in,out]    ber            A pointer to a sys_BerElement that will be allocated to keep track of the current position.
*                                  It is an input and output parameter for subsequent calls to sys_ldap_NextAttribute(). 
*                                  The sys_BerElement structure is opaque to the application. 
*                                  Free *ber when its use is completed using sys_ldap_ber_free().
* 
* @returns A pointer to a buffer containing the first attribute type in the entry if the request was successful 
*          or NULL if the request was not successful.
*/
char *sys_ldap_FirstAttribute(sys_LDAP *ld, sys_LDAPMessage *entry, sys_BerElement **ber);

/**
* @brief  This function returns the next attribute in an entry.
*
* The sys_ldap_NextAttribute() function takes an entry returned by sys_ldap_FirstEntry() or
* sys_ldap_NextEntry() and returns a pointer to a buffer containing the next attribute type in the entry.
* This string must be freed when its use is completed using sys_ldap_Memfree().
* The sys_ldap_FirstAttribute() and sys_ldap_NextAttribute() functions are used to step through the
* attributes in an LDAP entry.
*
* @param[in]        ld             LDAP handle.
* @param[in]        entry          The attribute information as returned by sys_ldap_FirstEntry() or sys_ldap_NextEntry().
* @param[in,out]    ber            This parameter specifies a pointer to a sys_BerElement that was allocated by 
*                                  ldap_FirstAttribute() to keep track of the current position. 
*                                  The sys_BerElement structure is opaque to the application. 
*                                  The caller should free ber using sys_ldap_ber_free() when finished.
* 
* @returns A pointer to a buffer containing the first attribute type in the entry if the request was successful 
*          or NULL when there are no attributes left to be retrieved.
*/
char *sys_ldap_NextAttribute(sys_LDAP *ld, sys_LDAPMessage *entry, sys_BerElement *ber);

/**
* @brief  This function is used to retrieve attribute values that are binary in nature from an LDAP entry
*         as returned by sys_ldap_FirstEntry() or sys_ldap_NextEntry().
*
* The sys_ldap_GetValuesLen() API returns a NULL-terminated array of pointers to sys_berval structures,
* each containing the length of and a pointer to a value.
* Use sys_ldap_ValueFreeLen() to free the returned attribute values when they are no longer needed.
*
* @param[in]        ld             LDAP handle.
* @param[in]        entry          Specifies an LDAP entry as returned from sys_ldap_FirstEntry() or sys_ldap_NextEntry().
* @param[in,out]    target         Specifies the attribute whose values are desired.
* 
* @returns A NULL-terminated array of pointers to berval structures if the request was successful
*          or NULL if the request was not successful.
*/
struct sys_berval **sys_ldap_GetValuesLen(sys_LDAP *ld, sys_LDAPMessage *entry, const char *target);

/**
* @brief  This function frees the memory allocated by the ldap_get_values_len() function.
*
* @param[in]        vals             Specifies a pointer to a null-terminated array of pointers to sys_berval structures,
*                                    as returned by sys_ldap_GetValuesLen().
*/
void sys_ldap_ValueFreeLen(struct sys_berval **vals);

/**
* @brief  This function parses a string representation of a distinguished name contained in str into its components, 
*         which are stored in dn as sys_ldap_ava structures, arranged in sys_LDAPAVA, sys_LDAPRDN, and sys_LDAPDN terms,
*         defined as:
*
* @code{.c}
  typedef struct sys_ldap_ava {
      char *la_attr;
      struct berval *la_value;
      unsigned la_flags;
  } sys_LDAPAVA;

  typedef sys_LDAPAVA** LDAPRDN;
  typedef sys_LDAPRDN* LDAPDN
  @endcode
*         
* The attribute types and the attribute values are not normalized.
* The la_flags can be either sys_LDAP_AVA_STRING or sys_LDAP_AVA_BINARY,
* the latter meaning that the value is BER/DER encoded and thus must be represented as,
* quoting from RFC 4514, " ... an octothorpe character ('#' ASCII 35) followed by the hexadecimal
* representation of each of the bytes of the BER encoding of the X.500 AttributeValue."
* The flags parameter to ldap_str2dn() can be one of the DN formats (e.g. sys_LDAP_DN_FORMAT_LDAPV3)
* which defines what DN syntax is expected (according to RFC 4514, RFC 1779 and DCE, respectively).
* The format can be ORed to the flags (e.g. sys_LDAP_DN_P_NOLEADTRAILSPACES).
*
* @param[in]        str            String that has to be converted.
* @param[out]       dn             DN derived from string
* @param[in]        flags          Flags
* 
* @returns sys_LDAP_SUCCESS if the request was successful or another LDAP error if the request was not successful.
*/
SINT sys_ldap_Str2Dn(const char *str, sys_LDAPDN *dn, unsigned flags);

/**
* @brief  This function performs the inverse operation of sys_ldap_Str2Dn(), yielding in str a string representation of dn.
*
* @param[in]        dn             DN that has to be converted.
* @param[out]       str            String derived from DN.
* @param[in]        flags          Flags
* 
* @returns sys_LDAP_SUCCESS if the request was successful or another LDAP error if the request was not successful.
* 
* @see sys_ldap_Str2Dn().
*/
SINT sys_ldap_Dn2Str(sys_LDAPDN dn, char **str, unsigned flags);
/** @} end of SYS-LDAP-API */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LDAP_E_H_ */

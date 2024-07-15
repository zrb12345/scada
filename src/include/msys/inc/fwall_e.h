/**
********************************************************************************
* @file     fwall_e.h
* @author   WIKU
*
* @brief    Global declarations for the firewall API.
*
********************************************************************************
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2016
*******************************************************************************/

#ifndef __FWALL_E_H__                           /* Avoid multiple inclusion */
#define __FWALL_E_H__

#ifdef __cplusplus
extern  "C"
{
#endif

#include <mtypes.h>

/**
 * @addtogroup SYS-FWALL-DEF-NEW
 * @{
 */

/*--- Defines ---*/
/**
 * @name API decorations
 */
#define FW_RULE_FLAGS       UINT32      /**< Combination of several flags */
#define FW_RULE_ACTIONS     UINT32      /**< Parameter is of type action */
#define FW_RULE_DIRECTION   UINT32      /**< Parameter is of type direction */
#define FW_RULE_PROTOCOL    UINT32      /**< Parameter is of type protocol */
#define FW_TYPES            UINT32      /**< Parameter specifies filter type */
/** @} */

/**
 * @anchor SYS_FW_FILTER_TYPE
 * @name Filter types
 */
#define FW_TYPE_IPV4        0x10000000  /**< IPv4 (layer 3) filter */
#define FW_TYPE_MAC         0x80000000  /**< MAC (layer 2) filter */
/** @} */

/**
 * @anchor SYS_FW_DIRECTIONS
 * @name Packet direction flags
 */
#define FW_RULE_DIR_IN      0x00000100  /**< Filter incoming packets */
#define FW_RULE_DIR_OUT     0x00000200  /**< Filter outgoing packets */
/** @} */

/**
 * @anchor SYS_FW_FILTER_ACTIONS
 * @name Packet processing flags (actions)
 */
#define FW_RULE_ACT_ACCEPT  0x00001000  /**< Accept the packet */
#define FW_RULE_ACT_REJECT  0x00002000  /**< Reject the packet */
/** @} */

/**
 * @anchor SYS_FW_PROTOCOLS
 * @name Protocol filter flags
 */
#define FW_RULE_PROT_UDP    0x00000001  /**< Filter UDP packets */
#define FW_RULE_PROT_TCP    0x00000002  /**< Filter TCP packets */
#define FW_RULE_PROT_ICMP   0x00000004  /**< Filter ICMP packets */
/** @} */

/**
 * @anchor SYS_FW_ICMPDEFS
 * @name Special ICMP filtering options
 */
#define FW_RULE_ICMP_ANY        0xFFFF  /**< Apply rule for any ICMP type */
/** @} */

/**
 * @anchor SYS_FW_LOGFACILITIES
 * @name Logging facilities
 */
#define FW_LOG_TYPE              UINT32 /**< Logging categories */
#define FW_LOG_INFORMATION            1 /**< Informational log entry */
#define FW_LOG_WARNING                2 /**< Log entry that users should note */
#define FW_LOG_ERROR                  3 /**< Log entry in case of error */
/** @} */
/** @} End of SYS-FWALL-DEF */

/**
 * @addtogroup SYS-FWALL-IP
 * @{
 */

/**
********************************************************************************
* @brief        Installs a IPv4 filter as specified in the input parameters.
*
* @note         This function must be called before adding any IP or ICMP
*               filtering rules.
*
* @see          See also \ref FW_BASICS_NOTES "Basic concepts and notes"
*
* @param[in]    Direction           #FW_RULE_DIR_IN or #FW_RULE_DIR_OUT
* @param[in]    DefaultAction       #FW_RULE_ACT_ACCEPT or #FW_RULE_ACT_REJECT
*
* @retval       #OK     Filer successfully installed
* @retval       #ERROR  Filter already installed or invalid parameter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIpFilterAdd(FW_RULE_DIRECTION Direction, FW_RULE_ACTIONS DefaultAction);

/**
********************************************************************************
* @brief        Removes the IPv4 filter specified in the input parameters as
*               well as the IP and ICMP rules added by sys_FwIpRuleAdd() respectively
*               sys_FwIcmpRuleAdd().
*
* @param[in]    Direction           #FW_RULE_DIR_IN or #FW_RULE_DIR_OUT
*
* @retval       #OK     Filer successfully removed
* @retval       #ERROR  Filter not installed or invalid parameter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIpFilterDel(FW_RULE_DIRECTION Direction);

/**
********************************************************************************
* @brief        Adds a IP rule the to IPv4 filter for the given direction.
*
* @note         This is the replacement for sys_FwIpInputFilterAdd().
*
* @note         sys_FwIpFilterAdd() must be called before adding any IPv4
*               filtering rules.
*
* @note         Currently only IPv4 is supported. Acronyms used hereinafter:
*               Src = Source (origin), Dst = Destination (target)
*
* @see          See also \ref FW_BASICS_NOTES "Basic concepts and notes"
*
* @param[in]    pSrcAddrStart   Src IP address range start (NULL=any)
* @param[in]    pSrcAddrEnd     Src IP address range end (NULL=\p pSrcStartAddr)
* @param[in]    SrcPortStart    Src Port range start (0=any)
* @param[in]    SrcPortEnd      Src Port range end (0=\p SrcPortStart)
* @param[in]    pDstAddrStart   Dst IP address range start (NULL=any)
* @param[in]    pDstAddrEnd     Dst IP address range end (NULL=\p pDstAddrStart)
* @param[in]    DstPortStart    Dst Port range start (0=any)
* @param[in]    DstPortEnd      Dst Port range end (0=\p DstPortStart)
* @param[in]    pIfName         Interface the rule will apply to (NULL=any)
* @param[in]    Flags           A combination of <b>one</b> \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*",
*                               <b>one</b> \ref SYS_FW_FILTER_ACTIONS "FW_RULE_ACT_*" flags,
*                               and <b>one</b> of the FW_RULE_PROT_* except #FW_RULE_PROT_ICMP
*
* @return       The identifier (ID) of the new rule
* @return       #ERROR  Could not add a rule to the specified IPv4 filter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIpRuleAdd(const char *pSrcAddrStart, const char *pSrcAddrEnd,
                       UINT16 SrcPortStart, UINT16 SrcPortEnd,
                       const char *pDstAddrStart, const char *pDstAddrEnd,
                       UINT16 DstPortStart, UINT16 DstPortEnd,
                       const char *pIfName, FW_RULE_FLAGS Flags);

/**
********************************************************************************
* @brief        Adds a ICMP rule the to the IPv4 filter for the given direction.
*
* @note         sys_FwIpFilterAdd() must be called before adding any ICMP
*               filter rules.
*
* @note         Currently only IPv4 is supported. Acronyms used hereinafter:
*               Src = Source (origin), Dst = Destination (target)
*
* @note         Use sys_FwIcmpRuleDel() to delete a specific ICMP rule.
*
* @see          See also \ref FW_BASICS_NOTES "Basic concepts and notes"
*
* @param[in]    pSrcAddrStart   Src IP address range start (NULL=any)
* @param[in]    pSrcAddrEnd     Src IP address range end (NULL=\p pSrcStartAddr)
* @param[in]    pDstAddrStart   Dst IP address range start (NULL=any)
* @param[in]    pDstAddrEnd     Dst IP address range end (NULL=\p pDstAddrStart)
* @param[in]    IcmpType        ICMP type (e.g. 0x03: Destination unreachable).
*                               #FW_RULE_ICMP_ANY = all ICMP packets
* @param[in]    IcmpCode        ICMP code (e.g. 0x05: Source route failed).
*                               If IcmpType is set to #FW_RULE_ICMP_ANY, IcmpCode
*                               will default to #FW_RULE_ICMP_ANY in any case.
* @param[in]    pIfName         Interface the rule will apply to (NULL=any)
* @param[in]    Flags           A combination of <b>one</b> \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*"
*                               and <b>one</b> \ref SYS_FW_FILTER_ACTIONS "FW_RULE_ACT_*" flags
*                               (others are ignored).
*
* @return       The identifier (ID) of the new rule
* @return       #ERROR  Could not add a rule to the specified IPv4 filter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIcmpRuleAdd(const char *pSrcAddrStart, const char *pSrcAddrEnd,
                         const char *pDstAddrStart, const char *pDstAddrEnd,
                         UINT32 IcmpType, UINT32 IcmpCode,
                         const char *pIfName, FW_RULE_FLAGS Flags);

/**
********************************************************************************
* @brief        Deletes all IP filter rules from the given filter.
*
* @note         This is the replacement for sys_FwIpInputFilterDel().
*
* @note         Only IP rules will be deleted. ICMP rules, if any, will remain.
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags
*
* @retval       #OK     IP rules were successfully deleted (regardless if
*                       there were rules or not)
* @retval       #ERROR  Could not the delete one or more of the IP rules
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIpRuleDelAll(FW_RULE_DIRECTION Direction);

/**
********************************************************************************
* @brief        Deletes the given IP filter rule from the given filter.
*
* @note         This is the replacement for sys_FwIpInputFilterDel().
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags
* @param[in]    RuleId      \p RuleId returned by sys_FwIpRuleAdd()
*
* @retval       #OK     The specified IP rule was successfully deleted
* @retval       #ERROR  Could not the delete the specified IP rule
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIpRuleDel(FW_RULE_DIRECTION Direction, SINT32 RuleId);

/**
********************************************************************************
* @brief        Deletes all ICMP filter rules from the given filter.
*
* @note         Only ICMP rules will be deleted. IP rules, if any, will remain.
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags
*
* @retval       #OK     ICMP rules were successfully deleted (regardless if
*                       there were rules or not)
* @retval       #ERROR  Could not the delete one or more of the ICMP rules
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIcmpRuleDelAll(FW_RULE_DIRECTION Direction);

/**
********************************************************************************
* @brief        Deletes the given ICMP filter rule from the given filter.
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags
* @param[in]    RuleId      \p RuleId returned by sys_FwIcmpRuleAdd()
*
* @retval       #OK     The specified ICMP rule was successfully deleted
* @retval       #ERROR  Could not the delete the specified ICMP rule
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwIcmpRuleDel(FW_RULE_DIRECTION Direction, SINT32 RuleId);
/** @} End of SYS-FWALL-IP */

/**
 * @addtogroup SYS-FWALL-MAC
 * @{
 */

/**
********************************************************************************
* @brief        Installs a MAC address based filter.
*
* @note         This function must be called before adding any MAC filtering rules.
*
* @param[in]    Direction       #FW_RULE_DIR_IN or #FW_RULE_DIR_OUT
* @param[in]    DefaultAction   #FW_RULE_ACT_ACCEPT or #FW_RULE_ACT_REJECT
* @param[in]    pIfBindings     CSV list with interface names (e.g. "eth0,em0,cip0").
*                               If NULL, all interfaces will be bound.
*
* @retval       #OK     Filer successfully installed
* @retval       #ERROR  Filter already installed or invalid parameter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwMacFilterAdd(FW_RULE_DIRECTION Direction, FW_RULE_ACTIONS DefaultAction,
                          const char *pIfBindings);

/**
********************************************************************************
* @brief        Removes the MAC filter specified in the input parameters as
*               well as the rules added by sys_FwMacRuleAdd().
*
* @param[in]    Direction           #FW_RULE_DIR_IN or #FW_RULE_DIR_OUT
*
* @retval       #OK     Filer successfully removed
* @retval       #ERROR  Filter not installed or invalid parameter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwMacFilterDel(FW_RULE_DIRECTION Direction);

/**
********************************************************************************
* @brief        Adds a rule the to MAC filter for the given direction. To specify
*               a range of MAC addresses, use \p pMask.
*               Example: Apply rule for all devices from Bachmann electronic GmbH
*
*               MAC = 00:10:7E:00:00:00, Mask = FF:FF:FF:00:00:00
*               -> Rule applies if the first three octets match
*
* @note         This is the replacement for sys_FwMacInputFilterAdd().
*
* @note         sys_FwMacFilterAdd() must be called before adding any MAC
*               filtering rules.
*
* @note         Any combination of "00:00:00:00:00:00" and "FF:FF:FF:FF:FF:FF"
*               is possible, but specifying "00:00:00:00:00:00" has the same
*               effect as omitting it (in meaning of does not care).
*
*
* @see          See also \ref FW_BASICS_NOTES "Basic concepts and notes"
*
* @param[in]    pSrcAddr        Optional: Desired source MAC address
* @param[in]    pSrcMask        Optional: Mask for a range of source addresses
* @param[in]    pDstAddr        Optional: Desired destination MAC address
* @param[in]    pDstMask        Optional: Mask for a range of destination addresses
* @param[in]    FrameType       Ethernet frame type (e.g. 0x0800 = IPv4)
* @param[in]    Flags           A combination of <b>one</b> \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*"
*                               and <b>one</b> \ref SYS_FW_FILTER_ACTIONS "FW_RULE_ACT_*" flags
*                               (others are ignored)
*
* @return       >0      The Id of the new rule
* @return       #ERROR  Could not add rule or invalid parameter(s)
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwMacRuleAdd(const char *pSrcAddr, const char *pSrcMask,
                        const char *pDstAddr, const char *pDstMask,
                        UINT16 FrameType, FW_RULE_FLAGS Flags);

/**
********************************************************************************
* @brief        Deletes the given MAC filter rule from the given filter.
*
* @note         This is the replacement for sys_FwMacInputFilterDel().
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags
* @param[in]    RuleId      \p RuleId returned by sys_FwMacRuleAdd()
*
* @retval       #OK     The specified MAC rule was successfully deleted
* @retval       #ERROR  Could not the delete the specified MAC rule
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwMacRuleDel(FW_RULE_DIRECTION Direction, SINT32 RuleId);

/**
********************************************************************************
* @brief        Deletes all MAC filter rules from the given filter.
*
* @note         This is the replacement for sys_FwMacInputFilterDelAll().
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags
*
* @retval       #OK     MAC rules were successfully deleted (regardless if
*                       there were rules or not)
* @retval       #ERROR  Could not the delete one or more of the MAC rules
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwMacRuleDelAll(FW_RULE_DIRECTION Direction);

/** @} End of SYS-FWALL-MAC */

/**
 * @addtogroup SYS-FWALL-DIAG
 * @{
 */

/**
********************************************************************************
* @brief        Displays the IP filter rules for the given direction.
*
* @note         This is the replacement for sys_FwIpFilterShow().
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags (0 for all)
*
* @retval       #OK     This function will return with success
*
* @since        `MCore V3.97`
*******************************************************************************/
STATUS sys_FwIpRuleShow(FW_RULE_DIRECTION Direction);

/**
********************************************************************************
* @brief        Displays the MAC filter rules for the given direction.
*
* @note         This is the replacement for sys_FwMacFilterShow().
*
* @param[in]    Direction   <b>One</b> of the \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" flags (0 for all)
*
* @retval       #OK     This function will return with success
*
* @since        `MCore V3.97`
*******************************************************************************/
STATUS sys_FwMacRuleShow(FW_RULE_DIRECTION Direction);

/**
********************************************************************************
* @brief        Provide information for the given rule (if specified) and how
*               may packets matched the rule.
*
* @param[in]    RuleId          ID of the rule as returned by sysFwIpRuleAdd(),
*                               sys_FwIcmpRuleAdd() or sys_FwMacRuleAdd().
*                               Set to zero for the match count of all rules.
* @param[out]   pAcceptCount    Address where to store number of accepted packets
* @param[out]   pRejectCount    Address where to store number of rejected packets
* @param[out]   pFlags          Optional; If not NULL and a valid \p RuldId was
*                               specified, a combination of
*                               \ref SYS_FW_FILTER_TYPE "FW_TYPE_*",
*                               \ref SYS_FW_FILTER_ACTIONS "FW_RULE_ACT_*"
*                               and \ref SYS_FW_DIRECTIONS "FW_RULE_DIR_*" (as
*                               passed when the rules was configured) will
*                               be stored at the specified address.
*
* @note         If \p RuleId is zero, the total number of accepted/rejected packets
*               will be returned. \p pFlags, even if specified, remains unchagned
*               in that case.
*
* @retval       OK      Call completed successfully
* @retval       ERROR   Could not access configuration, invalid rule ID,
*                       no filters installed or invalid parameter
*
* @since        `MCore V3.97`
*******************************************************************************/
SINT32 sys_FwStatisticGet(SINT32 RuleId, UINT64 *pAcceptCount, UINT64 *pRejectCount,
                          FW_RULE_FLAGS *pFlags);


/** @} End of SYS-FWALL-MAC */

/**
 * @addtogroup SYS-FWALL-DEF-OLD
 * @{
 */

/**
 * @anchor SYS_FW_OLDPROTS
 * @name Deprecated protocol filter flags (`MCore V4.00` and lower)
 */
#ifndef FW_FIELD_TCP
#define FW_FIELD_TCP    8
#endif                                  /**< Filter out TCP packets */

#ifndef FW_FIELD_UDP
#define FW_FIELD_UDP    9
#endif                                  /**< Filter out UDP packets */

#ifndef FW_FIELD_ICMP
#define FW_FIELD_ICMP   10
#endif                                  /**< Filter out ICMP packets */

/** @} */
/** @} End of SYS-FWALL-DEF-OLD */

/**
 * @addtogroup SYS-FWALL-OLD
 * @{
 */

/**
 * @anchor SYS_FW_OLDFUNCS
 * @name Deprecated functions (`MCore V4.00` and lower)
 */

/**
********************************************************************************
* @deprecated Users of `MCore` >= V4.10 should see sys_FwIpFilterAdd() instead.
*
* @brief Install a IP filter rule to reject frames from specified IP and/or
*        port range.
*
* @note  If not already present, this function will install a IP input filter
*        which accepts packets per default.
*
* @b Example:<br> Block all ICMP frames from 192.0.0.150:
* @code{.c}
*     sys_FwIpInputFilterAdd("192.0.0.150", 0, 0, 0, 0, 0, 0, FW_FIELD_ICMP)
* @endcode
*
* @param[in] srcIpStart     Start of source IP range to reject (e.g. "192.168.0.1");
*                           \p NULL to ignore source IP address (\p srcIpEnd must be \p NULL
*                           as well!)
* @param[in] srcIpEnd       End of source IP range to reject (e.g. "192.168.0.100").
*                           \p NULL means same as \p srcIpStart.
* @param[in] dstIp          Destination IP to reject (e.g. "192.168.0.200").
*                           \p NULL to ignore destination IP address
* @param[in] srcPortStart   Start of source port range to reject (e.g. 6000).
*                           If \p srcPortStart != 0 requires \p Protocol also to be != 0.
*                           Use 0 to ignore source port number.
* @param[in] srcPortEnd     End of source port range to reject (e.g. 6500).
*                           0 means same as \p srcPortStart.
* @param[in] dstPortStart   Start of destination port range to reject (e.g. 3500).
*                           If \p dstPortStart != 0 requires \p Protocol also to be != 0.
*                           Use 0 to ignore destination port number.
* @param[in] dstPortEnd     End of destination port range to reject (e.g. 3550).
*                           0 means same as \p dstPortStart.
* @param[in] Protocol       Type of protocol (#FW_FIELD_TCP , #FW_FIELD_UDP ,
*                           #FW_FIELD_ICMP)
*
* @retval >0 Filter \p RuleId
* @retval -1 Filter install failed.
*
* @see sys_FwIpInputFilterDel()
*
* @since `MCore V3.95`
*******************************************************************************/
SINT32 sys_FwIpInputFilterAdd(char *srcIpStart, char *srcIpEnd, char *dstIp,
                              UINT32 srcPortStart, UINT32 srcPortEnd,
                              UINT32 dstPortStart, UINT32 dstPortEnd,
                              UINT32 Protocol);

/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwIpRuleDel() instead.
*
* @brief Delete the specified \p RuleId (works just for IP-filter).
*
* @param[in] RuleId     \p RuleId to be deleted.
*
* @retval #OK    \p RuleId was successfully removed.
* @retval #ERROR Failed to delete the specified \p RuleId or the \p RuleId was invalid.
*
* @since `MCore V3.95`
*******************************************************************************/
STATUS sys_FwIpInputFilterDel(SINT32 RuleId);

/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwIpRuleDelAll() instead.
*
* @brief Delete all the \p RuleId's.
*
* @retval #OK    All \p RuleId's (and the rule group) were successfully removed.
* @retval ERROR  Failed to delete the rule group or there was now rule group.
*
* @since `MCore V3.95`
*******************************************************************************/
STATUS sys_FwIpInputFilterDelAll();


/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwIpRuleShow() instead.
*
* @brief Show MAC filter information.
*
* @return Always returns #OK
*
* @since `MCore V3.95`
*******************************************************************************/
STATUS sys_FwIpFilterShow();

/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwMacRuleAdd() instead.
*
* @brief Install a MAC filter rule do reject frames with specified \p EtherType
*        from the specified source MAC address.
*
* @note  If not already present, this function will install a MAC input filter
*        which accepts packets per default.
*
* @note This filter will be applied to all the available ethernet interfaces.
*
* @b Example:<br>
* Block all IPv4 frames from Bachmann devices:
* @code{.c}
*     sys_FwMacInputFilterAdd("00:10:7E:00:00:00", "FF:FF:FF:00:00:00", 0x0800)
* @endcode
*
* @param[in] Mac        Source MAC address to reject (e.g. "00:10:FA:03:8f:f1")
* @param[in] Mask       Source MAC address mask to reject (e.g. "FF:FF:FF:00:00:00").
*                       \p NULL for "FF:FF:FF:FF:FF:FF"
* @param[in] EtherType  Type of protocol to reject (e.g. 0x0800 for IPv4)
*
* @retval >0 Filter \p RuleId which can be used to remove the filter
*            (see function sys_FwMacInputFilterDel).
* @retval -1 Filter install failed.
*
* @since `MCore V3.95`
*******************************************************************************/
SINT32 sys_FwMacInputFilterAdd(char *Mac, char *Mask, UINT16 EtherType);

/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwMacRuleDel() instead.
*
* @brief Delete the specified \p RuleId (works just for MAC-filter).
*
* @param[in] RuleId     \p RuleId to be deleted.
*
* @retval #OK    \p RuleId was successfully removed.
* @retval #ERROR Failed to delete the specified \p RuleId or the \p RuleId was invalid.
*
* @since `MCore V3.95`
*******************************************************************************/
STATUS sys_FwMacInputFilterDel(SINT32 RuleId);

/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwMacRuleDel() instead.
*
* @brief Delete all MAC filter rules.
*
* @retval #OK    All rules were successfully removed.
* @retval #ERROR Failed to delete all rules.
*
* @since `MCore V3.95`
*******************************************************************************/
STATUS sys_FwMacInputFilterDelAll();


/**
********************************************************************************
* @deprecated Users of `MCore` >= V3.97 should see sys_FwMacRuleShow() instead.
*
* @brief Show MAC filter information.
*
* @return Always returns #OK
*
* @since `MCore V3.95`
*******************************************************************************/
STATUS sys_FwMacFilterShow();

/** @} End of @anchor SYS_FW_OLDFUNCS */

/** @} End of SYS-FWALL-OLD */

#ifdef __cplusplus
}
#endif

#endif  /* __FWALL_E_H__ */


/*--------------------------------------------------------------------------
* Module: m1com.dll
*
*
*---------------------------------------------------------------------------
*
* Desc: This file describes the interface of the m1com.dll.
*       
*---------------------------------------------------------------------------
* COPYRIGHT BY BACHMANN ELECTRONIC GmbH 2010
*-------------------------------------------------------------------------*/

#define M1C_VERSION "V1.08.99 Release"


#ifndef _M1COM_H
#define _M1COM_H

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN 
#define OUTCAST
#include <windows.h>
#include <WinCrypt.h>

#ifndef M1COM
#define M1COM extern "C" __declspec(dllimport)
#endif

#endif

#ifdef __linux__

#define CALLBACK
#define OUTCAST (std::ostream)

#ifndef M1COM
#ifdef __cplusplus
#define M1COM extern "C"
#else
#define M1COM
#endif
#endif

#endif // __linux__

#include <mtypes.h>
#include <msys.h>
#include <svi.h>
#include <res.h>
#include <smi.h>
#include <rfs.h>
#include <vhd.h>


////// defines // /////////////////////////////////////////////////////////////

#define M1C_MAX_ADDRESS_LEN    256      /**< Maximal length of a target address.*/

/**
@deprecated use M1C_MAX_SEND_BUFLEN and TARGET_GetMaxCallSize instead
*/
#define M1C_MAX_BUFLEN              1888    /**< Maximal size of userdata in an RPC call
//                                               ( max_udp - max_rpc_header: 2048-160 ).*/
//
#define M1C_MAX_SEND_BUFLEN         1888    /** Maximal size of userdata of an RPC call */
#define M1C_MAX_RECV_BUFLEN         SMI_DATALEN    /** Maximal size of userdata of an RPC reply */


////// errorcodes /////////////////////////////////////////////////////////////

#define M1C_BASE					    0x81100000      //indicates that m1com is error source
                                                        //for other error sources refer to msys.h

#define M1C_OK                          0               //everything is fine
#define M1C_E_MEM_ALLOC                 (M1C_BASE|0x01) //not enough memory 
#define M1C_E_INVALID_PARTNER           (M1C_BASE|0x02) //network connection closed by partner
#define M1C_E_WSA_INIT                  (M1C_BASE|0x03) //WINSOCK could not be initialized
#define M1C_E_ENET_DOWN                 (M1C_BASE|0x04) //Network is down
#define M1C_E_ADDRESS_SUPPORT           (M1C_BASE|0x05) //address family not supported by protocol family
#define M1C_E_SOCKET_PROGRESS           (M1C_BASE|0x06) //operation now in progress
#define M1C_E_NOMORE_SOCKETS            (M1C_BASE|0x07) //no more sockets
#define M1C_E_PROTOCOL                  (M1C_BASE|0x08) //wrong protocol type for socket
#define M1C_E_SOCKET                    (M1C_BASE|0x09) //socket error
#define M1C_E_SOCKET_ACCESS             (M1C_BASE|0x0A) //invalid socket access
#define M1C_E_INVALID_IPA               (M1C_BASE|0x0B) //bad address
#define M1C_E_SOCKET_CONN               (M1C_BASE|0x0C) //socket connect error
#define M1C_E_INVALID_SOCKET            (M1C_BASE|0x0D) //invalid socket
#define M1C_E_RECEIVE_SIZE              (M1C_BASE|0x0E) //message too long
#define M1C_E_SOCKET_INUSE              (M1C_BASE|0x0F) //socket already in use
#define M1C_E_TIME_OUT                  (M1C_BASE|0x10) //connection timed out
#define M1C_E_WINSOCKET                 (M1C_BASE|0x11) //WINSOCK error
#define M1C_E_RPCCALL_STATE             (M1C_BASE|0x13) //invalid XiD
#define M1C_E_PROG_MISMATCH             (M1C_BASE|0x14) //module with that number not found on controller  
#define M1C_E_PROC_UNAVAIL              (M1C_BASE|0x15) //SMI function not supported by module
#define M1C_E_INV_RESPONSE              (M1C_BASE|0x16) //invalid response
#define M1C_E_AUTH_ERROR                (M1C_BASE|0x17) //authentication failed
#define M1C_E_NO_CONN	                (M1C_BASE|0x18) //no connection established
#define M1C_E_QSOAP_FRAME               (M1C_BASE|0x19) //invalid QSOAP frame
#define M1C_E_NEG_RESP	                (M1C_BASE|0x1A) //SMI: negative response
#define M1C_E_SSL                       (M1C_BASE|0x1B) //SSL error
#define M1C_E_INVALID_PARAMETER	        (M1C_BASE|0x1C) //invalid parameter
#define M1C_E_INVALID_HANDLE	        (M1C_BASE|0x1E) //invalid handle
#define M1C_E_NOT_INITIALIZED           (M1C_BASE|0x1F) //not initialized
#define M1C_E_NO_VAR                    (M1C_BASE|0x20) //variable not found
#define M1C_E_LOCAL_FILE_ERROR          (M1C_BASE|0x22) //error accessing the local file
#define M1C_E_HTTP_ERROR                (M1C_BASE|0x23) //HTTP error
#define M1C_E_NO_PERMISSON              (M1C_BASE|0x24) //access denied
#define M1C_E_UNKNOWN_HOST              (M1C_BASE|0x25) //host not found
#define M1C_E_REMOTE_FILE_ERROR         (M1C_BASE|0x26) //error accessing the remote file
#define M1C_E_UNSPECIFIED_ERROR         (M1C_BASE|0x27) //unspecified
#define M1C_E_NO_LIST                   (M1C_BASE|0x28) //no observation list
#define M1C_E_INVALID_STATE             (M1C_BASE|0x29) //operation not allowed in the current state
#define M1C_E_WRONG_MSYS                (M1C_BASE|0x30) //function not supported by used MSYS


/** @brief Helper to get a textual representation of the source of an error.
*
* @param[in]   errorCode   Returncode.
* @param[out]  ErrorSrc    Buffer to store the string.
* @param[in]   ErrorSrcLen Lenght of the buffer.
*/
M1COM VOID GetErrorSrc(SINT32 errorCode, CHAR8 * errorSrc, UINT32 errorSrcLen);


/** @brief Helper to get a description of an error.
*
* @param[in]   errorCode   Returncode.
* @param[out]  ErrorMsg    Buffer to store the string.
* @param[in]   errorMsgLen Lenght of the buffer.
*/
M1COM VOID GetErrorMsg(SINT32 errorCode, CHAR8 * errorMsg, UINT32 errorMsgLen);


////// Handles //////////////////////////////////////////////////////////////
/*
* In m1com every object is represented by a handle.
* There are functions to create handles of the different types.
* If you have created a handle you have to dispose it later on.
*/


/** @brief Handle to a target.
*
* A target represents an M1 controller from a communication point of view.
* 
*/
typedef VOID*  M1C_H_TARGET;


/** @brief Handle to a module.
*
* A module handle represents a software module instance on an M1 controller.
* 
*/
typedef VOID*  M1C_H_MODULE; 

/** @brief Handle to a variable.
*
* A variable handle represents an SVI variable on an M1 controller.
*/
typedef VOID*  M1C_H_VARIABLE; 


/** @brief Handle to an obseravtion list.
*
* A list handle represents a list of variables, which can be observed on an M1 controller.
*/
typedef VOID*  M1C_H_OBSLIST;

////// Enumerations ///////////////////////////////////////////////////////////

/** Supported network protocols. 
* Used as parameter to create a target.
*/
typedef UINT32 M1C_PROTOCOL; 
 
#define	M1C_TCP    0 	/**< RPC over TCP: Fast communication to port 3500 on the 
                             target. Used in local networks.*/

#define	M1C_QSOAP  1    /**< QSOAP(XML-RPC): Communication to port 80 on the target,
                             or a user defined port. Based on HTTP and can be
                             forwarded by proxies. */

#define	M1C_SSL    2    /**< Secure Socket Layer: Encrypted communication to port 443.
							 Can be forwarded by proxies.*/

#define	M1C_UDP    4    /**< RPC over UDP: Fast communication to different ports on the target.
                             Used in local networks. */


/** @brief Possible states of a connection to a target */

/*
*    +---------------+  --connect--> +------------+
*    |  M1C_OFFLINE  |               | M1C_ONLINE |
*    +---------------+  <--close--   +------------+
*	         A                              |
*			 |                              |
*          close                        Network Error	             
*            |      					    |
*            |       +------------------+   |
*            --------|   M1C_ERROR      |<---
*                    +------------------+
*/
typedef UINT32 M1C_CONNECTION_STATE;

#define M1C_ONLINE   0
#define M1C_OFFLINE  1
#define M1C_ERROR    2



/** @brief Possible keys for TARGET_Set/GetUintParam()*/
typedef  UINT32 M1C_UINT_PARAM_KEY; 

#define M1C_PROXY_USED  0x0     /**< If set to a value!=0 QSOAP and SSL
                                     use the proxy specified by 
                                     M1C_PROXY_HOST and M1C_PROXY_PORT.*/
#define M1C_PROXY_PORT  0x1     /**< Port of the proxy.*/
#define M1C_QSOAP_PORT  0x2     /**< If set to a value!=0 QSOAP 
                                     connections are established to the
				     specified port.*/ 
#define M1C_IGNORE_SERVER_CERT   0x3 /**< If value!=0 SSL does not validate
                                          server certificates.*/
#define M1C_COUNT_SOCKETS  0x4       /**< If value!=0, value indicates the
                                          count of sockets that are wished to be 
                                          connected to the target. Default is 1.
                                          A multithreaded application may benefit
                                          from using more than 1 socket.*/
#define M1C_IGNORE_SERVER_CERT_CN   0x5    /**< If value!=0 SSL does not validate
                                          the CN or SAN Attributes of server certificates.*/



/** @brief Possible keys for TARGET_Set/GetStringParam()*/
typedef UINT32 M1C_STRING_PARAM_KEY; 
 	
#define M1C_PROXY_HOST  0x00010000         /**< Address of the proxy 
								                (e.g.: "my.proxy.org", 127.0.0.1)*/
#define M1C_PROXY_USERNAME   0x00010001    /**< username for proxy authentication*/
#define M1C_PROXY_PASSWD     0x00010002    /**< password for proxy authentication*/  
#define	M1C_QSOAP_PATH       0x00010003    /**< additional path in the QSOAP header
                                                (for use with reverse proxies)   */
#define	M1C_VHD_SESSIONNAME  0x00010004    /**< this string will be used as VHD Session name */


////// Structures /////////////////////////////////////////////////////////////

/** @brief Holds the name of a module*/
typedef struct
{	
	CHAR8 name[M_MODNAMELEN_A];       /**< Name of the module. */
} MODULE_NAME;


/** @brief Structure for a list of module names.*/
typedef struct
{
	UINT16 countModules;       /**< Count of module names.*/
	MODULE_NAME * names;       /**< Array of module names.     */
} MODULE_LIST;


/** @brief Structure for holding the information about a variable. 
*
*  After calling TARGET_InitVariables you can access the variable information with VARIABLE_GetInfo.
*/
typedef struct                          
{                                       
    CHAR8   name[M_MODNAMELEN_A + 1 + SVI_ADDRLEN_A]; /**< Symbolic name of the
                                                          variable in the form 
                                                          "MOD_NAME/VAR_NAME" */
    UINT16 format;           /**< Format of the variable as defined in svi.h.*/
    UINT16 len;              /**< Size of the variable in bytes. */
} VARIABLE_INFO;


/** @brief List of variable informations. */
typedef struct
{
	UINT32 countVariables;    /**< Count of variables. */
	VARIABLE_INFO* varInfo;   /**< Array of information about the variables. */
} VARIABLE_INFO_LIST;



/** @brief Structure for read and write operations on a variable. 
*   Variable read and write functions operate on variable buffers.
*   After TARGET_ReadVariable(s) the read value is stored in buffer and lastError is set to M1C_OK.
*   If the read operation fails, an according error information is stored in lastError.
*   Before TARGET_WriteVariable(s) the buffer has to be set with the value to be written.
*   After  TARGET_WriteVariable(s) lastError indicates, if the operation has been completed.
*/	 
typedef struct
{
	M1C_H_VARIABLE varHandle;   /**< Handle to the variable.*/
	UINT32 bufferLen;           /**< Size of the allocated buffer. */
	UINT8* buffer;              /**< Buffer to read from, or write to. */
	SINT32 lastError;           /**< Errorcode of the last read or write operation. 
                                         M1C_OK: success, fail otherwise */
} VARIABLE_BUFFER;


/** @brief Structure for target finding.
*/
typedef struct 
{
	RES_EXTPING_R extPingR;       // information about the target as described in res.h
	CHAR8          hostAddr[16];   // IP address of the target
} TARGET_INFO;


/**
@brief Returns the version of m1com.dll
@param[out] version buffer to store the version in
@param[in]  strLen  length of the buffer
*/
M1COM VOID M1C_GetVersion(CHAR8* version, UINT32 strLen);


/**
@brief Creates a handle to a target

The handle is needed for all further operations on the target. 
TARGET_Dispose has to be called to perform cleanup after usage.
Target is in state M1C_OFFLINE after it has been created.
After creation of a targetHandle you have to call TARGET_Connect to start
communicating with the target.
@param[in]  address Name or IP of the target. (e.g.: "m1", "10.0.0.1" )
@param[in]  protocol The protocol to be used for the communication.
@param[in]  timeout Connection timeout in milliseconds.
@return A handle to the target, NULL if operation fails.
*/
M1COM M1C_H_TARGET TARGET_Create(CHAR8* address, M1C_PROTOCOL protocol, UINT32 timeout);


/**
@brief Sets a special parameter for the target.

@param[in] targetHandle Handle to the target
@param[in] key   The identifier of the parameter.
@param[in] value The value of the parameter
@return  M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_SetUintParam(M1C_H_TARGET targetHandle, M1C_UINT_PARAM_KEY key, UINT32 value);


/**
@brief Sets a special parameter for the target.

@param[in] targetHandle Handle to the target
@param[in] key   The identifier of the parameter.
@param[in] value The value of the parameter
@param[in] valueLen The length of the buffer
@return  M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_SetStringParam(M1C_H_TARGET targetHandle, M1C_STRING_PARAM_KEY key, CHAR8* value, UINT32 valueLen);


/**
@brief Returns the parameter.

@param[in] targetHandle Handle to the target
@param[in] key   The identifier of the parameter.
@return  The value of the parameter. 0, if not set
*/
M1COM UINT32 TARGET_GetUintParam(M1C_H_TARGET targetHandle, M1C_UINT_PARAM_KEY key);


/**
@brief Returns the parameter.

@param[in] targetHandle Handle to the target
@param[in] key   The identifier of the parameter.
@return  The value of the parameter. NULL, if not set
*/
M1COM CHAR8*  TARGET_GetStringParam(M1C_H_TARGET targetHandle, M1C_STRING_PARAM_KEY key);


/**
@brief Returns the maximum length of an rpc call
@param[in] targetHandle Handle to the target
@param[out] maxCallSize the maximum length of an rpc call
@return  M1C_E_INVALID_HANDLE if the handle is not valid, M1C_OK otherwise
*/
M1COM SINT32 TARGET_GetMaxCallSize(M1C_H_TARGET targetHandle, UINT32* maxCallSize);




/**
@brief  Sets a certcontext to be used as ssl client certificat
@param[in] targetHandle Handle to the target
@param[in] clientCertContext a cert context (see wincrypt documentation)
@return M1C_E_INVALID_HANDLE if the handle is not valid, M1C_OK otherwise
*/
#ifdef _WIN32
M1COM SINT32 TARGET_SetSSLClientCertificateContext(M1C_H_TARGET targetHandle, PCERT_CONTEXT clientCertContext);
#endif

/**
@brief Connects to the target

Login is called if user!=NULL AND password!=NULL, otherwise no login is performed. Empty strings are treated as NULL.
Login2 is automatically used, if the MSYS version supports it.
A connection to the RES module is established in case of success.
@param[in] targetHandle The target to connect to.
@param[in] user         Name of the user.
@param[in] password     Plain text password.
@param[in] toolName     Name of tool. Just use "" if you don't know what it is used for.
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_Connect(M1C_H_TARGET targetHandle, CHAR8* user, CHAR8* password, CHAR8* toolName);


/**
@brief Returns the session live time in s of the connection to the target.
TARGET_RenewConnection has to be called before the session expires.
@param[in] targetHandle The handle to the target.
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_GetSessionLiveTime(M1C_H_TARGET targetHandle, UINT32* sessionLiveTime);

/**
@brief Renews the connection to the target.
If Session Life Time is configured for the target the connection session is renewed with this function
@param[in] targetHandle The handle to the target.
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_RenewConnection(M1C_H_TARGET targetHandle);

/**
@brief Closes all connections to the target.

The communication to the target is stopped and all module handles of the target are disposed!
If a login has been performed, logout is called. 
@param[in] targetHandle The target to close.
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_Close(M1C_H_TARGET targetHandle);


/**
@brief Performs cleanup

A logout from the target is called if needed, all network connections are closed.
All modules of the target are disposed!
The handle is no longer valid after calling this function.
If other threads use the target or modules of the target the caller has to stop them before disposing the target!

Further usage of the handle will lead to M1C_E_INVALID_HANDLE.
@param[in] targetHandle The handle to be disposed
*/
M1COM VOID TARGET_Dispose(M1C_H_TARGET targetHandle);


/**
@brief Returns the state of the communication.

@param[in] targetHandle The target to check the connection.
@param[out] state The state of the connection: M1C_ONLINE, M1C_OFFLINE, or M1C_ERROR
@return M1C_E_INVALID_HANDLE if the targetHandle is not valid, M1C_OK otherwise
*/
M1COM SINT32 TARGET_GetConnectionState(M1C_H_TARGET targetHandle, M1C_CONNECTION_STATE* state);


/**
@brief Returns the state of the target.

An INF_PROC_ALIVE is sent to the target and appstate and reboot count are returned.

@param[in] targetHandle Handle to the target
@param[out] appState The appstate of the target. For further information see res.h.
@param[out] rebootCount Count of reboots of the target. 
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_GetTargetState(M1C_H_TARGET targetHandle, UINT16* appState, UINT16* rebootCount);


/**
@brief Creates a handle to a software module.

The handle is needed for all further operations on the module.
The target referenced by targetHandle has to be connected before calling this function.
A call to MODULE_Connect is required before further usage of the handle.
MODULE_Dispose may be called to perform cleanup after usage.
Otherwise a call of TARGET_Close() or TARGET_Dispose() will dispose the module.
@param[in] name  The name of the software module
@param[in]  targetHandle Handle to a connected target.
@return an M1C_H_MODULE
*/
M1COM M1C_H_MODULE TARGET_CreateModule(M1C_H_TARGET targetHandle, CHAR8* name);

/**
@brief Establishes a connection to the module.

If protocol UDP is used, a new socket to the module is created.
Otherwise existing sockets are reused.

@param[in]  moduleHandle Handle to the module
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 MODULE_Connect(M1C_H_MODULE moduleHandle);


/**
@brief Performs cleanup

Note: RES module can not be disposed with this function.
The handle is no longer valid after calling this function.
If other threads use the module the caller has to stop them before disposing the module!

Further usage of the handle will lead to M1C_E_INVALID_HANDLE.
@param[in] moduleHandle The handle to be disposed
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 MODULE_Dispose(M1C_H_MODULE moduleHandle);


/**
@brief Performs an SMI call to the module.

With this function every SMI call to the target can be performed.
This function is threadsafe.

@param[in]  moduleHandle Handle to the module
@param[in]  proc		 Procedure number of the function to call.
@param[in]  version		 Version of the procedure.
@param[in]  send		 Buffer for data to be sent to the procedure.
@param[in]  sendSize	 Size of the send buffer. Has to be <= M1C_MAX_CALL_BUFLEN
@param[out] recv		 Buffer for the reply of the procedure.
@param[in]  recvSize	 Size of the receive buffer. Has to be <= M1C_MAX_REPLY_BUFLEN
@param[in]  timeout	     Timeout in milliseconds
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 MODULE_SendCall(M1C_H_MODULE moduleHandle, UINT32 proc, UINT32 version, const VOID* send, UINT16 sendSize, VOID* recv, UINT16 recvSize, UINT32 timeout);


/**
@brief Returns the count of all modules on the target.
@param[in]  targetHandle Handle to the target
@param[out]  moduleCount the count of modules on the target
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_GetCountModules(M1C_H_TARGET targetHandle, UINT16* moduleCount);


/**
@brief Retrieves all module names of the target 
@param[in]  targetHandle Handle to the target
@param[in]  moduleCount The maximum count of module names that fit into moduleList
@param[out] moduleList  Count and names of the modules. Has to be allocated by the caller.
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 TARGET_GetModules(M1C_H_TARGET targetHandle, const UINT16 moduleCount, MODULE_LIST* moduleList);


/**
@brief Retrieves the count of variables of the module.

@param[in]  moduleHandle Handle to the module
@param[out]  varCount Count of variables of the module
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 MODULE_GetCountVariables(M1C_H_MODULE moduleHandle, UINT32* varCount);


/**
@brief Retrieves all variables of the module 

From a performance point of view it is better to call this function with a variable list,
big enough to hold all variables at once, than finding the size by calling MODULE_GetCountVariables first.
@param[in]  moduleHandle Handle to a module
@param[in]  varCount The maximum count of variables that fit into varList
@param[out] varList  Has to be allocated by the caller.
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 MODULE_GetVariables(M1C_H_MODULE moduleHandle, const UINT32 varCount, VARIABLE_INFO_LIST* varList);


/**
@brief Creates a handle to a process variable. 

The state of the variable referred by the handle is M1C_OFFLINE after calling this function.
Before using it, it has to be resolved by TARGET_InitVariables.

@param[in]  targetHandle Handle to the target
@param[in] name    The absolute name of the variable in the form: "module/varname".
@return a M1C_H_VARIABLE
*/
M1COM M1C_H_VARIABLE TARGET_CreateVariable(M1C_H_TARGET targetHandle, CHAR8* name);


/**     
@brief Initializes the variables from the target.

The format and the bufferlen of the variable are initialized, if it exists on the target.
Internally the addresses of the variables are resolved.
The count of variables, that could not be resolved is returned. In that case iterate over your variables and
call VARIABLE_GetState to find the unresolved variables.

Performance hint: Do not call TARGET_InitVariables in a loop for every single variable. Try to pack as many variables as possible into one call.

@param[in] targetHandle Handle to the target.
@param[in] variables List of variable handles
@param[in] count of variables in the list
@return Count of variables successfully initialized. A return value < 0 indicates an error condition.
*/
M1COM SINT32 TARGET_InitVariables(M1C_H_TARGET targetHandle, M1C_H_VARIABLE* variables, UINT32 countVariables);


/**
@brief Reads the actual values of the variables into the buffer.

This function performs a synchronous read of all variables inside variableBuffers.
Returned is the count of variables read successfully. If not all variables could be read the corresponding
variable buffers lastError is set to an error number.

The caller is responsible for allocating the buffer correctly! 
The size of the buffer has to be VARIABLE_GetBufferLen(varHandle).
@param[in] targetHandle Handle to the target.
@param[in, out] variableBuffers List of variable buffers.
@param[in] count of buffers in the list
@return Count of variables successfully read. A return value < 0 indicates an error condition.
*/
M1COM SINT32 TARGET_ReadVariables(M1C_H_TARGET targetHandle, VARIABLE_BUFFER* variableBuffers, UINT32 countVariables);


/**
@brief Writes the values stored in variable buffer to the target and updates the state.

This function  performs a synchronous write of all variables inside variableBuffers.
Returned is the count of variables written successfully. If not all variables could be written the corresponding variable
buffers lastError is set to an error number.
The caller is responsible for allocating the buffer correctly!
The size of the buffer has to be VARIABLE_GetBufferLen(varHandle).
@param[in] targetHandle Handle to the target.
@param[in, out] variableBuffers List of variable buffers.
@param[in] count of buffers in the list
@return Count of variables written successfully. A return value < 0 indicates an error condition.
*/
M1COM SINT32 TARGET_WriteVariables(M1C_H_TARGET targetHandle, VARIABLE_BUFFER* variables, UINT32 countVariables);


/**
@brief Reads the value of the variable into the variable buffer.

This function performs a synchronous read of a single variable.

@param[in] targetHandle Handle to the target.
@param[in] variableHandle Handle to the variable to read
@param[out] buffer buffer to store the value
@param[in] bufferSize the size of the buffer
@return M1C_OK: successfully read, error otherwise
*/
M1COM SINT32 TARGET_ReadVariable(M1C_H_TARGET targetHandle, M1C_H_VARIABLE variableHandle, VOID* buffer, UINT32 bufferSize);

/**
@brief Writes the value stored in buffer to the target.

This function performs a synchronous write to a single variable.

@param[in] targetHandle Handle to the target.
@param[in] variableHandle Variable to write
@parmam[in] buffer buffer containing the value to write
@param[in] bufferSize the size of the buffer
@return M1C_OK: successfully written, error otherwise
*/
M1COM SINT32 TARGET_WriteVariable(M1C_H_TARGET targetHandle, M1C_H_VARIABLE variableHandle, VOID* buffer, UINT32 bufferSize);

/**
@brief Disposes the variable handle. 

Further usage of the handle will lead to M1C_E_INVALID_HANDLE.
@param[in] variable The handle to be disposed.
*/
M1COM VOID VARIABLE_Dispose(M1C_H_VARIABLE variable);

/**
@brief Returns the state of the variable.

@param[in] variable  Handle to the variable.
@param[out] state  The state of the variable.
@return M1C_OK: success, Otherwise: fail (M1C_E_INVALID_HANDLE  )
*/
M1COM SINT32 VARIABLE_GetState(M1C_H_VARIABLE variable, M1C_CONNECTION_STATE* state);


/**
@brief Returns type information about the variable.

@param[in] variable  Handle to the variable.
@param[out] varInfo  Information about the variable.
@return M1C_OK: success, Otherwise: fail (M1C_E_INVALID_HANDLE  )
*/
M1COM SINT32 VARIABLE_GetInfo(M1C_H_VARIABLE variable, VARIABLE_INFO* varInfo);


/**
@brief Helper to get the length of the array.

@param[in] varInfo
@return The length of the array
*/
             
M1COM UINT32 VARIABLE_getArrayLen(VARIABLE_INFO* varInfo);

/**
@brief Helper to get the buffer length needed for a VARIABLE_BUFFER

This function returns the needed length, as expected by the read and write functions.
@param[in] varInfo
@return The length of the buffer
*/
M1COM UINT32 VARIABLE_GetBufferLen(VARIABLE_INFO* varInfo);

/**
@brief Helper to get the base datatype as defined in svi.h

@param[in] varInfo
@return The base data type as declared in svi.h
*/
M1COM UINT32 VARIABLE_getBaseDataType(VARIABLE_INFO* varInfo);

/**
@brief Is the variable readable?

@param[in] varInfo  
@return TRUE if the variable is readable
*/
M1COM BOOL8  VARIABLE_IsReadable(VARIABLE_INFO* varInfo);

/**
@brief Is the variable writable?

@param[in] varInfo
@return TRUE if the variable is writable
*/
M1COM BOOL8  VARIABLE_IsWritable(VARIABLE_INFO* varInfo);


/**
@brief Creates an observation list.

For all variables inside variableBuffers vhd lists are allocated on the controller. The returned handle can be used to update, reset and dispose the lists.
@param[in] targetHandle Handle to the target.
@param[in, out] variableBuffers List of variable buffers. The variables have to be initialized before.
@param[in] countVariables Count of buffers in the list.
@return A handle to an ObservationList. NULL indicates failure.
*/
M1COM  M1C_H_OBSLIST TARGET_CreateObservationList(M1C_H_TARGET targetHandle, VARIABLE_BUFFER* variableBuffers, UINT32 countVariables);

/**
@brief Disposes the observation list.

The allocated vhd lists on the controller are removed and the local allocated memory is freed.
The obsListHandle is invalid afterwards.
@param[in] obsListHandle Handle to the observation list.
@return M1C_OK if successful, errorcode otherwise.
*/
M1COM  SINT32 OBSLIST_Dispose(M1C_H_OBSLIST obsListHandle);

/**
@brief Updates all variable buffers of the observation list to the actual values on the controller.

The first call to OBSLIST_Update will update all values of the contained variables.
Subsequent calls will only update changed variables.
@param[in] obsListHandle Handle to the observation list.
@param[out] indexList Returns the indices of the changed variables. The indices refer to variableBuffers passed to TARGET_CreateObservationList.
@param[in] listSize Size of indexList
@return Count of changed variables, errorcode otherwise.
*/
M1COM SINT32 OBSLIST_Update(M1C_H_OBSLIST obsListHandle, SINT32* indexList, UINT32 listSize);

/**
@brief Resets the observation list.

All allocated vhd lists associated with this observation list on the controller will be resetted.
The next call to OBSLIST_Update will update all values of the contained variables. 
@param[in] obsListHandle Handle to the observation list.
@return M1C_OK if successful, errorcode otherwise.
*/
M1COM SINT32 OBSLIST_Reset(M1C_H_OBSLIST obsListHandle);


/**
@brief Copies a file from the local file system to a remote target.
@param[in] targetHandle     Handle to the target
@param[in] remoteFileName	max size=80  ( msys.h:   M_PATHLEN )
@param[in] localFileName	max size=260 ( windef.h: MAX_PATH  )
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 RFS_CopyToTarget(M1C_H_TARGET targetHandle, CHAR8 *remoteFileName, CHAR8 *localFileName); 


/**
@brief Copies a file from the remote target to the local file system.
@param[in] targetHandle         Handle to the target
@param[in] localFileName		max size=260 ( windef.h: MAX_PATH  )
@param[in] remoteFilename		max size=80  ( msys.h:   M_PATHLEN )
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 RFS_CopyFromTarget(M1C_H_TARGET targetHandle, CHAR8 *localFileName, CHAR8 *remoteFilename); 


/**
@brief Copies a file on the remote target.
@param[in] targetHandle Handle to the target
@param[in] destFile  	max size=80  ( msys.h:   M_PATHLEN )
@param[in] srcFile		max size=80  ( msys.h:   M_PATHLEN )
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 RFS_CopyRemote(M1C_H_TARGET targetHandle, CHAR8 *destFile, CHAR8 *srcFile); 


/**
@brief Deletes a file from a remote target.
@param[in] targetHandle Handle to the target
@param[in] filename		max size=80  ( msys.h:   M_PATHLEN )
@return M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 RFS_Remove(M1C_H_TARGET targetHandle, CHAR8 *filename); 


/**
@brief Callback function to be passed to RFS_ListDirectory. The function is called for each file found.
@param listItem Description of the found file
@param userParam The userparam passed to RFS_ListDirectory
@return: True to receive more calls, false to stop the enumeration of files.
*/
typedef BOOL8 (CALLBACK *ListDirCallBack) (RFS_LISTDIR_ITEM * listItem, VOID* userParam);

/**
@brief Lists the files in the specified directory. For each file found the callback cb is called.
@param targetHandle handle to the target
@param directory absolute path of the directory
@param cb callback function
@param userParam parameter that is passed to the callback function  
@return: M1C_OK: success, Otherwise: fail
*/
M1COM SINT32 RFS_ListDirectory(M1C_H_TARGET targetHandle, CHAR8 *directory, ListDirCallBack cb, VOID * userParam); 

/**
@brief Lookup for M1 targets on the network. Uses UDP broadcast to find the targets.
       The broadcasts are sent to all networks connected to the local machine.
	   Note: Broadcasts may be restricted by the switches on your LAN. (VLAN)
	         In that case you can scan a range of addresses with the function TARGET_SmiPing.
@param[in]  timeout:  timeout in ms to wait for responses
@param[out] targetInfos: buffer to store the found information
@param[in]  infosLen: number elements of the targetInfos buffer
@return     count of found targets
*/
M1COM SINT32 TARGET_BroadcastSmiPing( UINT32 timeout, TARGET_INFO * targetInfos, UINT32 len );


/**
@brief Sends an SMI ExtPing to the specified address, using the specified protocol. 
       If there is an M1, it will send back an extping reply.
	   This function can be used to scan a range of addresses for M1 targets, even if broadcasts are suppressed by the network.
@param[in]  addr: address of the target
@param[in]  timeout:  timeout in ms to wait for response
@param[in]  protocol: protocol to use(M1C_UDP, M1C_TCP, M1C_QSOAP or M1C_SSL)
@param[out] extping_r: struct containing information about the target. If extping_r->retCode != M1C_OK the contents of extping_r are undefined.
@return M1_OK if a target was found, Otherwise: no M1 found
*/
M1COM SINT32 TARGET_SmiPing(CHAR8* addr, UINT32 timeout, M1C_PROTOCOL protocol, RES_EXTPING_R * extping_r );


#endif

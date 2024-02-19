#ifndef __SERVER_H__
#define __SERVER_H__


typedef struct Server Server;
typedef void (*InvalidClient)(int _information);
typedef void (*GotMessege)(int _information,char _buffer[],size_t _bufferlen);
typedef void (*Fail)(int _information);


/**  
 * @brief Create a new server with given user parameters.  
 * @param[in] InvalidClient - function the get a message to the user if the client is invalid.
 * @param[in] GotMessege - server replay to user if he got a signal from a valid user.
 * @param[in] Fail - send a message if the server failed.
 * @return Server* - on success
 * @retval NULL on fail 
 * @complexity O(1)
 */
Server* ServerCreate(InvalidClient,GotMessege,Fail); 
/**  
 * @brief Destroy the server and all his components.  
 * @param[in] _server - the server structure with all his components.
 * @return void
 * @complexity O(1)
 */
void ServerDestroy(Server** _server);
/**  
 * @brief Run the server.  
 * @param[in] _server - the server structure with all his components.
 * @return void
 * @complexity O(n)
 */
void Run(Server* _server);
/**  
 * @brief Send message to the selected user.  
 * @param[in] _client - void pointer to client number.
 * @param[in] _arr[] - the array with the message the server send.
 * @param[in] _length - length of the array.
 * @return void
 * @complexity O(1)
 */
void SendMessege(void* _client, char _arr[], unsigned int _length);






#endif /* __SERVER_H__ */

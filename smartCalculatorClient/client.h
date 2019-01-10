#ifndef __CLIETN_H__
#define __CLIETN_H__	
#include "memory_pool.h"
#include "video_util.h"
typedef struct _global_resource{
	memory_pool_t *pool;
	int sem_id;
	uint8_t *rgb24;
	VideoV4l2 camera;
	uint8_t *resize_rgb24;
	uint32_t resize_width;
	uint32_t resize_height;
	volatile float weight;
	volatile float price;
	volatile uint8_t class_id;
	key_t sem_key;
	const char *server_ip;
	short server_port;
	int balance_fd;
	int accept_flag;
}global_resource;

#pragma pack(1)
typedef struct _protocol{
	uint8_t head;
	uint8_t type;
	int length;
}calculatorProtocol;
#pragma pack()

//Main resource initilization.
int init_global_resource(global_resource * resource,const char *server_ip,short server_port,size_t pool_size,uint8_t sem_numbs,uint32_t resize_width,uint32_t resize_height,key_t simkey,const char *camera_path,int frame_buff_count,const char *balance_path);
int release_global_resource(global_resource * resource);

//balance module pthread function.
void *balance_module_handle(void *arg);

//Dispaly module pthread fuction.
void *display_module_handle(void *arg);

//Control module pthread function.
void *control_module_handle(void *arg);

#endif
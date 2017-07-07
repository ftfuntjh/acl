#pragma once

struct req_t
{
	acl::string cmd;
};

struct res_t
{
	int status;
	acl::string msg;
};

//////////////////////////////////////////////////////////////////////////////

struct serv_info_t
{
	int status;
	acl::string name;
	int type;
	// Gson@optional
	acl::string owner;
	acl::string path;
	int proc_max;
	int proc_prefork;
	int proc_total;
	int proc_avail;
	int throttle_delay;
	int listen_fd_count;
	// Gson@optional
	acl::string notify_addr;
	// Gson@optional
	acl::string notify_recipients;
	std::map<acl::string, acl::string> env;
};

//////////////////////////////////////////////////////////////////////////////

struct list_req_t : req_t
{
};

struct list_res_t : res_t
{
	std::list<serv_info_t> data;
};

//////////////////////////////////////////////////////////////////////////////

struct stat_req_data_t
{
	acl::string path;
};

struct stat_req_t : req_t
{
	std::vector<stat_req_data_t> data;
};

struct stat_res_t : res_t
{
	std::vector<serv_info_t> data;
};

//////////////////////////////////////////////////////////////////////////////

struct start_req_data_t
{
	acl::string path;
};

struct start_req_t : req_t
{
	std::vector<start_req_data_t> data;

};

struct start_res_data_t
{
	int status;
	acl::string name;
	// Gson@optional
	acl::string path;
};

struct start_res_t : res_t
{
	std::vector<start_res_data_t> data;
};

//////////////////////////////////////////////////////////////////////////////

struct stop_req_data_t
{
	acl::string path;
};

struct stop_req_t : req_t
{
	std::vector<stop_req_data_t> data;
};

struct stop_res_data_t
{
	int status;
	acl::string path;
};

struct stop_res_t : res_t
{
	std::vector<stop_res_data_t> data;
};

//////////////////////////////////////////////////////////////////////////////

struct kill_req_data_t
{
	acl::string path;
};

struct kill_req_t : req_t
{
	std::vector<kill_req_data_t> data;
};

struct kill_res_data_t
{
	int status;
	acl::string path;
};

struct kill_res_t : res_t
{
	std::vector<kill_res_data_t> data;
};

//////////////////////////////////////////////////////////////////////////////

struct reload_req_data_t
{
	acl::string path;
};

struct reload_req_t : req_t
{
	std::vector<reload_req_data_t> data;
};

struct reload_res_data_t
{
	int status;
	int proc_count;
	int proc_signaled;
	acl::string path;
};

struct reload_res_t : res_t
{
	std::vector<reload_res_data_t> data;
};

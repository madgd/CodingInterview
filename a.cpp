//遍历某个文件夹下面的所有txt，生成对应的permission特征向量（151维），写入制定文件中
#include<iostream>     
#include<string>     
#include<io.h> 
#include <stdio.h>
#include<fstream>
using namespace std;
int transfer(string fileName, int exeNum = 0);
int readtxt(char* inpath);


struct A
{
	unsigned char x;
	unsigned char y;
	int z;
};
void main()
{
	string fileName = "D:\\b\\*.txt";//所有匹配目标文件类型
	transfer(fileName);
//	double a[2]; int intsize;
//	intsize = (int)(a + 1) - (int)a;
//	cout<< intsize;

}

int transfer(string fileName, int exeNum)//遍历所有目标类型文件，读取其内容，并执行readtxt
{
	_finddata_t fileInfo;
	long handle = _findfirst(fileName.c_str(), &fileInfo);

	if (handle == -1L)
	{
		cerr << "failed to transfer files" << endl;
		return false;
	}

	do
	{
		exeNum++;
		//cout << fileInfo.name << endl;
		string filepath = "D:\\b\\";
		filepath += fileInfo.name;
		cout << filepath << endl;
		char* p = const_cast<char*>(filepath.data());
		readtxt(p);

	} while (_findnext(handle, &fileInfo) == 0);
	cout << " .txt files' number:  " << exeNum << endl;

	return 0;
}

int readtxt(char* inpath)
{
	ifstream in(inpath);
	ofstream out("D:\\b\\results.txt", ios::app);
	string line;
	string per;
	string permission[151] = { "ACCESS_CHECKIN_PROPERTIES", "ACCESS_COARSE_LOCATION", "ACCESS_FINE_LOCATION", "ACCESS_LOCATION_EXTRA_COMMANDS", "ACCESS_MOCK_LOCATION", "ACCESS_NETWORK_STATE", "ACCESS_SURFACE_FLINGER", "ACCESS_WIFI_STATE", "ACCOUNT_MANAGER", "ADD_VOICEMAIL", "AUTHENTICATE_ACCOUNTS", "BATTERY_STATS", "BIND_ACCESSIBILITY_SERVICE", "BIND_APPWIDGET", "BIND_DEVICE_ADMIN", "BIND_DREAM_SERVICE", "BIND_INPUT_METHOD", "BIND_NFC_SERVICE", "BIND_NOTIFICATION_LISTENER_SERVICE", "BIND_PRINT_SERVICE", "BIND_REMOTEVIEWS", "BIND_TEXT_SERVICE", "BIND_TV_INPUT", "BIND_VOICE_INTERACTION", "BIND_VPN_SERVICE", "BIND_WALLPAPER", "BLUETOOTH", "BLUETOOTH_ADMIN", "BLUETOOTH_PRIVILEGED", "BODY_SENSORS", "BRICK", "BROADCAST_PACKAGE_REMOVED", "BROADCAST_SMS", "BROADCAST_STICKY", "BROADCAST_WAP_PUSH", "CALL_PHONE", "CALL_PRIVILEGED", "CAMERA", "CAPTURE_AUDIO_OUTPUT", "CAPTURE_SECURE_VIDEO_OUTPUT", "CAPTURE_VIDEO_OUTPUT", "CHANGE_COMPONENT_ENABLED_STATE", "CHANGE_CONFIGURATION", "CHANGE_NETWORK_STATE", "CHANGE_WIFI_MULTICAST_STATE", "CHANGE_WIFI_STATE", "CLEAR_APP_CACHE", "CLEAR_APP_USER_DATA", "CONTROL_LOCATION_UPDATES", "DELETE_CACHE_FILES", "DELETE_PACKAGES", "DEVICE_POWER", "DIAGNOSTIC", "DISABLE_KEYGUARD", "DUMP", "EXPAND_STATUS_BAR", "FACTORY_TEST", "FLASHLIGHT", "FORCE_BACK", "GET_ACCOUNTS", "GET_PACKAGE_SIZE", "GET_TASKS", "GET_TOP_ACTIVITY_INFO", "GLOBAL_SEARCH", "HARDWARE_TEST", "INJECT_EVENTS", "INSTALL_LOCATION_PROVIDER", "INSTALL_PACKAGES", "INSTALL_SHORTCUT", "INTERNAL_SYSTEM_WINDOW", "INTERNET", "KILL_BACKGROUND_PROCESSES", "LOCATION_HARDWARE", "MANAGE_ACCOUNTS", "MANAGE_APP_TOKENS", "MANAGE_DOCUMENTS", "MASTER_CLEAR", "MEDIA_CONTENT_CONTROL", "MODIFY_AUDIO_SETTINGS", "MODIFY_PHONE_STATE", "MOUNT_FORMAT_FILESYSTEMS", "MOUNT_UNMOUNT_FILESYSTEMS", "NFC", "PERSISTENT_ACTIVITY", "PROCESS_OUTGOING_CALLS", "READ_CALENDAR", "READ_CALL_LOG", "READ_CONTACTS", "READ_EXTERNAL_STORAGE", "READ_FRAME_BUFFER", "READ_HISTORY_BOOKMARKS", "READ_INPUT_STATE", "READ_LOGS", "READ_PHONE_STATE", "READ_PROFILE", "READ_SMS", "READ_SOCIAL_STREAM", "READ_SYNC_SETTINGS", "READ_SYNC_STATS", "READ_USER_DICTIONARY", "READ_VOICEMAIL", "REBOOT", "RECEIVE_BOOT_COMPLETED", "RECEIVE_MMS", "RECEIVE_SMS", "RECEIVE_WAP_PUSH", "RECORD_AUDIO", "REORDER_TASKS", "RESTART_PACKAGES", "SEND_RESPOND_VIA_MESSAGE", "SEND_SMS", "SET_ACTIVITY_WATCHER", "SET_ALARM", "SET_ALWAYS_FINISH", "SET_ANIMATION_SCALE", "SET_DEBUG_APP", "SET_ORIENTATION", "SET_POINTER_SPEED", "SET_PREFERRED_APPLICATIONS", "SET_PROCESS_LIMIT", "SET_TIME", "SET_TIME_ZONE", "SET_WALLPAPER", "SET_WALLPAPER_HINTS", "SIGNAL_PERSISTENT_PROCESSES", "STATUS_BAR", "SUBSCRIBED_FEEDS_READ", "SUBSCRIBED_FEEDS_WRITE", "SYSTEM_ALERT_WINDOW", "TRANSMIT_IR", "UNINSTALL_SHORTCUT", "UPDATE_DEVICE_STATS", "USE_CREDENTIALS", "USE_SIP", "VIBRATE", "WAKE_LOCK", "WRITE_APN_SETTINGS", "WRITE_CALENDAR", "WRITE_CALL_LOG", "WRITE_CONTACTS", "WRITE_EXTERNAL_STORAGE", "WRITE_GSERVICES", "WRITE_HISTORY_BOOKMARKS", "WRITE_PROFILE", "WRITE_SECURE_SETTINGS", "WRITE_SETTINGS", "WRITE_SMS", "WRITE_SOCIAL_STREAM", "WRITE_SYNC_SETTINGS", "WRITE_USER_DICTIONARY", "WRITE_VOICEMAIL",

	};
	bool feature[151] = { 0 };

	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			for (int i = 0; i < 151; i++)
			{
				if (line.find(permission[i]) != -1)
				{
					//cout << permission[i] << endl;
					feature[i] = 1;
				}
			}
		}
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl;
		return -1;
	}

	for (int i = 0; i < 151; i++)
	{
		cout << feature[i];
		out << feature[i]<<" ";
	}
	cout << endl;
	//out << inpath;
	out << endl;

	return 0;
}

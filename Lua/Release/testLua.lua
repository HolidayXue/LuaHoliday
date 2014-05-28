--package.cpath = package.cpath .. “.\\?.dll”
local json = require ("cjson");
local s = require "testHoliday";
print("hello world!");
G_TestObject1:print("I'm G_TestObject1\n");
G_TestObject2:print("I'm G_TestObject2\n");
s.print();
function testCall(str_input)
	print(str_input);	
	local table_jsonout = json.decode(str_input);
	print(table_jsonout["key"])
end
function test_call_first(str_input)
	print("test_call_first start\n");
	print(str_input);	
	local table_json_input = {};
	table_json_input["function_name"] = "test_call_second";
	table_json_input["param_email"] = "362783516@qq.com";
	table_json_input["param_name"] = "HolidayXue";	
	local str_output = json.encode(table_json_input);	
	G_TestObject1:print(str_output);	
	G_AsCInterFace1:test_calledFunction(str_output);
	print("")
	print("Up this is Asynchronous called!")
	
	print("test_call_first end\n")
	
end 
function test_call_second(str_input)
    print("test_call_second start\n")	
	print(str_input);	
	local table_jsonout = json.decode(str_input);	
	print(table_jsonout["param_name"]);
	local table_json_input = {};
	table_json_input["function_name"] = "test_call_first";
	table_json_input["param_email"] = "362783516@qq.com";
	table_json_input["param_name"] = "HolidayXue";	
	local str_output = json.encode(table_json_input);
	G_AsCInterFace1:test_calledFunction(str_output);
	
	print("test_call_second end\n")
end

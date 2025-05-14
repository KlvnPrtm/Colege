import requests
import json
import urllib3

# Disable SSL warnings
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

# Connection configuration
url = "https://sbx-nxos-mgmt.cisco.com/ins"
switchuser = "admin"
switchpassword = "Admin_1234!"

headers = {
    'content-type': "application/json"
}

# Function to send request
def send_request(command):
    payload = {
        "ins_api": {
            "version": "1.0",
            "type": "cli_show",
            "chunk": "0",
            "sid": "1",
            "input": command,
            "output_format": "json"
        }
    }
    response = requests.post(url, data=json.dumps(payload), headers=headers, auth=(switchuser, switchpassword), verify=False)
    return response.json()

# Create or overwrite the result file
with open('network_device_info.txt', 'w') as file:
    
    # 1. Display list of all interfaces
    file.write("1. List semua interface:\n")
    interfaces = send_request("show interface brief")
    file.write(json.dumps(interfaces, indent=2))
    file.write("\n\n")
    
    # 2. Display device information details
    file.write("\n2. Detail informasi perangkat:\n")
    device_info = send_request("show version")
    file.write(json.dumps(device_info, indent=2))
    file.write("\n\n")
    
    # 3. Display non-VLAN interface details
    file.write("\n3. Detail interface non-VLAN:\n")
    non_vlan_interfaces = send_request("show interface status")
    
    # Process and display non-VLAN interfaces
    
    if 'ins_api' in non_vlan_interfaces:
        result = non_vlan_interfaces['ins_api'].get('outputs', {}).get('output', {})
        if isinstance(result, list):
            result = result[0]
        if 'body' in result:
            interfaces_data = result['body']
            if 'TABLE_interface' in interfaces_data:
                interfaces = interfaces_data['TABLE_interface']['ROW_interface']
                if isinstance(interfaces, dict):
                    interfaces = [interfaces]
                non_vlan = [intf for intf in interfaces if not intf['interface'].startswith('Vlan')]
                file.write(json.dumps(non_vlan, indent=2))
            else:
                file.write("Tidak dapat menemukan tabel interface dalam hasil.\n")
        else:
            file.write("Tidak ada body dalam respons.\n")
    else:
        file.write("Format respons tidak sesuai dengan yang diharapkan.\n")
    # print (result)
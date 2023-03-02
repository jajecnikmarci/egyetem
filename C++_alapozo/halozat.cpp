#include <iostream>
#include <net-snmp/library/snmp.h>
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>

int main(int argc, char **argv) {
    // Initialize SNMP library
    init_snmp("snmpapp");

    // Create an SNMP session
    snmp_session session, *ss;
    snmp_sess_init(&session);
    session.peername = strdup("192.168.2.1"); // replace with your router IP address
    session.version = SNMP_VERSION_2c;
    session.community = (unsigned char *)"public"; // replace with your SNMP community string
    session.community_len = strlen((char *)session.community);
    ss = snmp_open(&session);
    if (!ss) {
        snmp_perror("snmp_open");
        exit(1);
    }

    // Retrieve information about connected devices
    netsnmp_variable_list *vars = NULL;
    oid oid_ifTable[] = { 1, 3, 6, 1, 2, 1, 2, 2, 1 }; // OID for the interface table
    size_t oid_ifTable_len = OID_LENGTH(oid_ifTable);
    int status = snmp_walk(ss, oid_ifTable, oid_ifTable_len, NULL, &vars);
    if (status == STAT_SUCCESS) {
        // Iterate through the retrieved data
        for (; vars; vars = vars->next_variable) {
            // Display the OID and value
            char value[SNMP_MAXBUF];
            snprint_variable(value, SNMP_MAXBUF, vars->name, vars->name_length, vars);
            std::cout << value << std::endl;
        }
    } else {
        snmp_sess_perror("snmp_walk", ss);
    }

    // Close the SNMP session
    snmp_close(ss);

    // Cleanup SNMP library
    snmp_shutdown("snmpapp");

    return 0;
}

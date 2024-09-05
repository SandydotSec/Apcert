rule APT_Malware_WallyGroup
{
    meta:
        description = "Detects APT malware distributed by Wally Group"
        author = "VNCERT"
        date = "2024-08-29"
        version = "1.0"

    strings:
        $manual_chm_md5 = "860F86601BC18DD205A5EDC0D57A658D"
		$menual_exe_md5 = "0DE9BE1ABA2E6DC3CE016FB24BFAAD9E"
		$particular_string_encrypted = { 5F 26 40 40 49 6F 79 6E 6F 40 40 39 6F 40 40 5D 6C 6C 58 7D 68 7D 40 40 50 73 7F 7D 70 40 40 48 79 71 6C 40 40 5F 50 43 2A 2E 2F 2B 79 28 2A 2A 7D 6F 68 78 }
        $ip_address_encrypted = { 0F 08 15 09 0B 0A 15 09 0E 08 15 09 03 }

    condition:
        (hash.md5(0, filesize) == $manual_chm_md5 or hash.md5(0, filesize) == $menual_exe_md5) or
        (all of ($particular_string_encrypted*) or all of ($ip_address_encrypted*))
}

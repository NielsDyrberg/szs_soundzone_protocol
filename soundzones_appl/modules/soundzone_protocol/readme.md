
# Documentation for SoundZone Protocol

version = 0.0.1

This file will list the commands in the SZP.

| Defines | Values |
|---|---|
| IPv | IPv4 |
| TCP port | 1695 ( Seemingly not used ) |

## Structure

[CID, {subCID}, payload ]
CID - Command ID
subCID - Sub command ID (Depends on the command)
payload - Data to send (Structure depends on the CID and subCID)

## Command overview

|CID | Name | Description |
|---|---|---|
| 0x01 | checkCon | Used to check connection, used for debug |
| 0x02 | enroll | Used by client to enroll |



## Commands

### 01 - checkCon

```request = [ 01 ]```

Successful:

```respone = [ 01 ]```

### 02 - enroll

```request = [ 02 ]```


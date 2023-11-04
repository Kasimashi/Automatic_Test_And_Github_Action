FROM mcr.microsoft.com/windows:2004

EXPOSE 3389

RUN net user administrator Stack0verflow
RUN net user administrator /active:yes

# I tried disabling the firewall; but this command errors as Windows Defender Firewall service 
# is not enabled; so presumably if the firewall's not running, it's not a firewall issue.
#RUN netsh advfirewall set allprofiles state off

# switch shell to powershell (note: pwsh not available on the image)
SHELL ["powershell", "-Command", "$ErrorActionPreference = 'Stop'; $ProgressPreference = 'SilentlyContinue'; $ExecutionPolicy = 'Unrestricted';"]

# enable RDP (value is 1 on the base image)
RUN Set-ItemProperty -Path 'HKLM:\System\CurrentControlSet\Control\Terminal Server' -Name 'fDenyTSConnections' -Type 'DWord' -Value 0
# per https://www.withinrafael.com/2018/03/09/using-remote-desktop-services-in-containers/
RUN Set-ItemProperty -Path 'HKLM:\System\CurrentControlSet\Control\Terminal Server' -Name 'TemporaryALiC' -Type 'DWord' -Value 1
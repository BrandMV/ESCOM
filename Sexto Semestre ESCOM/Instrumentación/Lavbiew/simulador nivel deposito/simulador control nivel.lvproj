<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="21008000">
	<Property Name="varPersistentID:{4EA2337B-B28A-4B2E-99AA-701E6B665F55}" Type="Ref">/My Computer/control on-off.vi/RS Bistable/reset</Property>
	<Property Name="varPersistentID:{7C4BC449-7A7C-4EBF-B67C-90CB7E00BACD}" Type="Ref">/My Computer/control on-off.vi/RS Bistable/error in</Property>
	<Property Name="varPersistentID:{8C8CE949-E4D3-467E-BA5F-EA82388AE27B}" Type="Ref">/My Computer/control on-off.vi/RS Bistable/output</Property>
	<Property Name="varPersistentID:{DAF3AF5C-70DE-42C7-8731-1EBC0289F25B}" Type="Ref">/My Computer/control on-off.vi/RS Bistable/error out</Property>
	<Property Name="varPersistentID:{E1C81BA7-5040-45A3-B04E-B2A7DA810E3A}" Type="Ref">/My Computer/control on-off.vi/RS Bistable/set</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="control on-off.vi" Type="VI" URL="../control on-off.vi">
			<Item Name="RS Bistable" Type="IIO Function Block">
				<Item Name="error in" Type="Variable"/>
				<Item Name="error out" Type="Variable"/>
				<Item Name="output" Type="Variable"/>
				<Item Name="reset" Type="Variable"/>
				<Item Name="set" Type="Variable"/>
			</Item>
		</Item>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>

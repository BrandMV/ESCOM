<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="21008000">
	<Property Name="varPersistentID:{039936C1-3908-45F4-9D2B-DA9644800C27}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/count up done</Property>
	<Property Name="varPersistentID:{520854E6-BD8A-469D-8D8A-2D6DC32D02B1}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/count down done</Property>
	<Property Name="varPersistentID:{5F9348B0-D9F9-4C55-83A8-B09A47F4E82B}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/preset value</Property>
	<Property Name="varPersistentID:{64138F1F-3EA8-4604-9147-27A2BB8FA333}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/error in</Property>
	<Property Name="varPersistentID:{750DE273-C231-4CE8-92F4-7AC58AE1C69D}" Type="Ref">/My Computer/CONTROL ACCESO.vi/RS Bistable/reset</Property>
	<Property Name="varPersistentID:{7BD58B2B-037A-4C14-99C8-A923D4216479}" Type="Ref">/My Computer/CONTROL ACCESO.vi/RS Bistable/output</Property>
	<Property Name="varPersistentID:{8C50CBAC-2844-4A21-9A71-A1A03F2B49EF}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/counter value</Property>
	<Property Name="varPersistentID:{9C454DA3-B8BD-4BE2-9599-D2F33FDE6566}" Type="Ref">/My Computer/CONTROL ACCESO.vi/RS Bistable/set</Property>
	<Property Name="varPersistentID:{9E47B72D-A70C-4174-AFCD-E5894831E823}" Type="Ref">/My Computer/CONTROL ACCESO.vi/RS Bistable/error in</Property>
	<Property Name="varPersistentID:{A553D78D-8314-4ED6-878F-902196951E8A}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/reset</Property>
	<Property Name="varPersistentID:{B3A2C52F-E6FA-4B23-B3AE-6371D1FED1BF}" Type="Ref">/My Computer/CONTROL ACCESO.vi/RS Bistable/error out</Property>
	<Property Name="varPersistentID:{DADFF43B-8485-4104-A4B1-709BD9E1F63A}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/error out</Property>
	<Property Name="varPersistentID:{DB94BE6A-5C1E-462E-B33B-612BB930FB02}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/load</Property>
	<Property Name="varPersistentID:{F4FE98C1-4453-4C6B-955F-A6EC4251063B}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/count up</Property>
	<Property Name="varPersistentID:{FF9C0399-F2AD-42B1-8796-F675AE0CD4D2}" Type="Ref">/My Computer/CONTROL ACCESO.vi/Count Up Down/count down</Property>
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
		<Item Name="CONTROL ACCESO.vi" Type="VI" URL="../CONTROL ACCESO.vi">
			<Item Name="Count Up Down" Type="IIO Function Block">
				<Item Name="count down" Type="Variable"/>
				<Item Name="count down done" Type="Variable"/>
				<Item Name="count up" Type="Variable"/>
				<Item Name="count up done" Type="Variable"/>
				<Item Name="counter value" Type="Variable"/>
				<Item Name="error in" Type="Variable"/>
				<Item Name="error out" Type="Variable"/>
				<Item Name="load" Type="Variable"/>
				<Item Name="preset value" Type="Variable"/>
				<Item Name="reset" Type="Variable"/>
			</Item>
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

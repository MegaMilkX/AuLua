
Init = function()
    o = GetObject();
    o:Beep();
    o:Bop();
    o:SetMsg("Initialized");
end

Update = function(data)
    Print(data);
    PrintObject(o);
end
def mail_merge(names, template):
    with open(names) as fnames, open(template) as tmpl:
        lnames = fnames.readlines()
        mail = tmpl.read()
    
    lmail = []
    for name in lnames:
        lmail.append(mail.replace("<name>", name.rstrip("\n")))
    return lmail
